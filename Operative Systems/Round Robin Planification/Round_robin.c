#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Colores para impresion a stdout.

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Opciones de la linea de comandos (bit fields).

#define NUM_PROCESSES	0x01
#define TIME_QUANTUM	0x02

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Prototipos de funcion.
void getSystem();
void getSystem();
void printSystem();
void schedule();
void WatingTime();
void printScheduling();
void addToQueue(int);
unsigned int executionRemained();
unsigned int getNextProcess();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cola de solicitudes.

typedef struct queue
{
	unsigned int p;
	struct queue* next;
} Queue;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Variables globales.

Queue* q = NULL;
int processes[100][3], nProcesses, tQuantum, scheduler[1000],WT[100];
unsigned int time = 0;
u_int8_t opciones;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	int opt;

	while((opt = getopt(argc, argv, "p:q:")) != -1){
		switch(opt){
			case 'p':
				nProcesses = atoi(optarg);
				printf("No de procesos: %d.\n", nProcesses);
				opciones |= NUM_PROCESSES;
				break;
			case 'q':
				tQuantum = atoi(optarg);
				printf("Time Quantum: %d.\n", tQuantum);
				opciones |= TIME_QUANTUM;
				break;
			default:
				exit(-1);
				break;
		}
	}

	if(opciones == (NUM_PROCESSES | TIME_QUANTUM)){
		getSystem();
		printSystem();
		schedule();
		WatingTime();
		printScheduling();
	}
	return 0;
}

void getSystem()
{
	int i;
	
	for(i=0; i<nProcesses; i++ )
	{
		printf("\n-------------------------------------\n");
		printf("Tiempo de llegada de p%d: ", i+1);
		scanf("%d", &processes[i][0]);
		printf("Tiempo de ejecucion para p%d: ", i+1);
		scanf("%d", &processes[i][1]);
		processes[i][2] = processes[i][1];
		printf("-------------------------------------\n");
	}
}

void printSystem()
{
	int i;
	printf("\nNuestro sistemas es:");
	printf("\nQuantum: %d", tQuantum);
	printf("\nPi:  AT BT RT");
	for(i=0; i<nProcesses; i++)
	{
		printf("\nP%d:  %d  %d  %d", i+1, processes[i][0], processes[i][1], processes[i][2]);
	}
	printf("\nLa cola de solicitud es: ");
	Queue* n = q;

	while(n != NULL){
		printf("P%d ",n->p);
		n = n->next;
	}
	printf("\n");
}

unsigned int executionRemained()
{
	int i;
	unsigned int x = 0;
	for(i=0; i<nProcesses; i++)
	{
		if(processes[i][2] > 0)
		{
			x = 1;
		}
	}
	return x;
}
void addToQueue(int i)
{
	Queue* n, *n1;
	n = (Queue*)malloc(sizeof(Queue));
	n->next = NULL;
	n->p = i;
	if(q == NULL)
	{
		q = n;
	}
	else
	{
		for(n1 = q ; n1->next!=NULL; n1=n1->next);
		n1 -> next = n;
	}
}

void addArrivedProcessesToq()
{
	int i;
	for(i=0; i<nProcesses; i++)
	{
		if(processes[i][0] == time)
		{
			addToQueue(i);
		}
	}
}

unsigned int getNextProcess()
{
	Queue *n;
	int x;
	if(q == NULL)
	{
		return -1;
	}
	else
	{
		x = q -> p;
		n = q;
		q = q -> next;
		free(n);
		return x;
	}
}

void schedule()
{
	unsigned int np, toRun, q, i;
	q = 0;
	addArrivedProcessesToq();
	while(executionRemained())
	{
		np = getNextProcess();
		if(np == -1)
		{
			/*
			here if there is no process in waiting q
			which mean the process get IDLe state.
			here in this program we put -1 in scheduler[time]
			which mean that the processor get IDLE in this time.
			
			*/
			scheduler[time] = -1;
			time++;
			addArrivedProcessesToq();
		}
		else
		{
			q = tQuantum;
			if(processes[np][2] < q)
			{
				q = processes[np][2];
			}
			for(i = q; i>0; i--)
			{
				scheduler[time]=np;
				time++;
				processes[np][2]--;
				addArrivedProcessesToq();
			}
			if(processes[np][2] > 0)
			{
				addToQueue(np);
			}
		}
		
		
		printSystem();
		int x;
		
	}
}

void printScheduling()
{
	int i;
	printf("\n\nScheduling: \n");
	for(i=0; i<time; i++)
	{
		printf("[%d-%d] (P%d) \n",i,i+1 ,scheduler[i]+1);
	}
	printf("\n\nWaiting Time: \n");
	for(i=0; i<nProcesses; i++)
	{
		printf("\nP%d: %d", i+1, WT[i]);
	}
	//counting Average Waiting Time...
	float AWT = 0.0;
	for(i=0; i<nProcesses; i++)
	{
		AWT = AWT+WT[i];
	}
	AWT = AWT/nProcesses;
	printf("\n\nTiempo promedio de espera: %f\n", AWT);
	
}

void WatingTime()
{
	int i;
	unsigned int releaseTime, t;
	for(i=0; i<nProcesses; i++)
	{
		
		for(t=time-1; scheduler[t]!= i; t--);
		releaseTime = t+1;
		WT[i] = releaseTime - processes[i][0] - processes[i][1];
	}
}