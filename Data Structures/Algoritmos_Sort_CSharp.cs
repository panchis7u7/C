using System;
using static System.Console;

namespace Algoritmos_Sort_CSharp
{
    class Program
    {
        public delegate void MainHandler(/*string[] args*/);
        private static Lista lista1 = new Lista("Pila1");

        static void Main(/*string[] args*/)
        {
            lista1.Ins(5);
            lista1.Ins(6);
            lista1.Ins(6);
            lista1.Ins(4);
            lista1.InsInicio(8);
            lista1.InsInicio(10);
            lista1.InsInicio(6);
            lista1.Ins(2);
            lista1.InsInicio(2);
            lista1.Ver();

            Nodo Encontrado = lista1.Buscar(2);
            WriteLine("\nBusqueda de nodo con info " + Encontrado.info + ": " + Encontrado);
            Nodo anterior = lista1.Anterior(8);
            WriteLine("Anterior de nodo con info " + anterior.Sig + ": " + anterior);
            WriteLine("Nodo con indice: " + lista1[3] + "\n");
            lista1[3] = 55;
            lista1.Ver();
            lista1.Del(2);
            lista1.Ver();

            WriteLine("\nLista de algoritmos para sortear la lista enlazada:");
            WriteLine("1.- Bubble Sort");
            WriteLine("2.- Insertion Sort (Version inline)");
            WriteLine("3.- Selection Sort (Version inline)");
            WriteLine("4.- Merge Sort");
            WriteLine("5.- Quick Sort");


            int cantidad = lista1.Cantidad();
            int desicion = int.Parse(Console.ReadLine());

            switch (desicion) {
                case 1:

            //Bubble Sort
            WriteLine("Bubble Sort");
            for (int i = 1; i < cantidad; i++)
            {
                for (int j = 0; j < cantidad - i; j++)
                {
                    if (lista1[j] > lista1[j + 1])
                    {
                        Swap(j, j + 1);
                    }
                }
            }
            lista1.Ver();
                    break;

                case 2:
                    //Insertion Sort version Inline
                    WriteLine("Insertion Sort");
                    int posAgujero = 0;
           
                    for (int i = 1; i < cantidad; i++)
                    {
                        posAgujero = i;
                        while (posAgujero > 0 && lista1[posAgujero] < lista1[posAgujero - 1])
                        {
                            Swap(posAgujero, posAgujero-1);
                            posAgujero = posAgujero - 1;
                        }
                    }
                    lista1.Ver();
                    break;

                case 3:
                    //Selection Sort version inline
                    WriteLine("Selection Sort");
                    int indiceMenor = 0;
                    for (int i = 0; i < cantidad-1; i++)
                    {
                        indiceMenor = i;
                        for (int j = i + 1; j < cantidad; j++)
                        {
                            if (lista1[j] < lista1[indiceMenor])
                                indiceMenor = j;
                        }
                        Swap(i, indiceMenor);
                    }
                    lista1.Ver();
                    break;

                case 4:
                    //Merge Sort
                    WriteLine("Merge Sort");
                    Lista lista2 = MergeSort(lista1);
                    lista2.Ver();
                    break;

                case 5:
                    //Quick Sort
                    WriteLine("Quick Sort");
                    QuickSort(0, lista1.Cantidad() - 1);
                    lista1.Ver();
                    break;

                default:
                    MainHandler MainDelegate = new MainHandler(Main);
                    MainDelegate.Invoke();
                    break;
            }
        }

        public static void QuickSort(int inicio, int final)
        {
            int iPivote = 0;
            if (inicio >= final)
                return;
            iPivote = Particion(inicio, final);

            //Casos inductivos
            QuickSort(inicio, iPivote - 1);
            QuickSort(iPivote + 1, final);
        }
        public static int Particion(int inicio, int final)
        {
            int pivote;
            int iPivote;
            //Se selecciona el ultimo elemento como pivote
            pivote = lista1[final];
            //Ponemos el indice del pivote como el primer elemento
            iPivote = inicio;
            for (int n = inicio; n < final; n++)
            {
                if(lista1[n] <= pivote)
                {
                    Swap(n, iPivote);
                    iPivote++;
                }
            }
            Swap(iPivote, final);
            return iPivote;
        }
        public static Lista Merge (Lista listaIzq, Lista listaDer)
        {
            Lista union = new Lista("Union");
            int indiceIzq = 0;
            int indiceDer = 0;
            int cantidadIzq = listaIzq.Cantidad();
            int cantidadDer = listaDer.Cantidad();
            //Recorremos mientras las dos listas tengan elementos son procesar
            while (indiceIzq < cantidadIzq && indiceDer < cantidadDer)
            {
                if(listaIzq[indiceIzq] <=  listaDer[indiceDer])
                {
                    union.Ins(listaIzq[indiceIzq]);
                    indiceIzq++;
                } else
                {
                    union.Ins(listaDer[indiceDer]);
                    indiceDer++;
                }
            }

            while(indiceIzq < cantidadIzq)
            {
                union.Ins(listaIzq[indiceIzq]);
                indiceIzq++;
            }

            while (indiceDer < cantidadDer)
            {
                union.Ins(listaDer[indiceDer]);
                indiceDer++;
            }
            return union;
        }

        public static Lista MergeSort(Lista lista)
        {
            int cantidad = lista.Cantidad();

            if (cantidad < 2)
                return lista;

            //Punto Medio
            int mitad = cantidad / 2;

            Lista izq = new Lista("ListaIzq");
            Lista der = new Lista("ListaDer");
            for (int n = 0; n < mitad; n++)
                izq.Ins(lista[n]);

            for (int n = mitad; n < cantidad; n++)
                der.Ins(lista[n]);

            //Casos inductivos
            Lista tmpI = MergeSort(izq);
            Lista tmpD = MergeSort(der);
            Lista ordenada = Merge(tmpI, tmpD);

            return ordenada;
        } 

        public static void Swap(int i1, int i2)
        {
            int temp = lista1[i1];
            lista1[i1] = lista1[i2];
            lista1[i2] = temp;
        }  
    }
    /// <summary>
    /// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// </summary>
    class Nodo
    {
        public int info;
        public Nodo Sig;

        public Nodo()
        {
            info = 0;
            this.Sig = null;
        }
        public Nodo(int info)
        {
            this.info = info;
            this.Sig = null;
        }

        public Nodo(Nodo x)
        {
            this.info = x.info;
            this.Sig = x.Sig;
        }

        public override string ToString()
        {
            return String.Format("[{0}]", info);
        }
    }

    /// <summary>
    /// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// </summary>
    class Lista
    {
        private Nodo le; 
        private Nodo ancla;
        private String identificacion;
        public Lista(String identificacion)
        {
            ancla = new Nodo();
            ancla.Sig = null;
            le = null;
            this.identificacion = identificacion;
        }

        public bool EstaVacia() {
            return (ancla == null) ? true : false;
        }

        public void Ins(int dato)
        {
            Nodo nuevo = new Nodo(dato);
            le = ancla;
            while (le.Sig != null)
            {
                le = le.Sig;
            }
            nuevo.Sig = null;
            le.Sig = nuevo;
        }

        public void InsInicio(int dato)
        {
            Nodo nuevo = new Nodo(dato);
            nuevo.Sig = ancla.Sig;
            ancla.Sig = nuevo;
        }

        public Nodo Buscar(int info)
        {
            le = ancla;
            //WriteLine("Nodos encontrados con la informacion: {0}", info);
            while (le.Sig != null)
            {
                le = le.Sig;
                if (le.info == info)
                {
                    //Write("[" + tmp.info + "]" + " ");
                    return le;
                }
            }
            return null;
        }

        public void Del(int info)
        {
            le = ancla;
            Nodo tmp = le;
            Nodo aux = Buscar(info);
            do
            {
                tmp = aux;
                Anterior(info).Sig = tmp.Sig;
                tmp.Sig = null;
                tmp = le;
                aux = Buscar(info);
            } while ((aux != null) && (EstaVacia() != true));
        }

        public Nodo Anterior(int info)
        {
            le = ancla;
            while (le.Sig != null && le.Sig.info != info)
                le = le.Sig;

            return le;
        }

        public int Cantidad()
        {
            le = ancla;
            int contador = 0;
            while(le.Sig != null)
            {
                le = le.Sig;
                contador++;
            }
            return contador;
        }

        public void Ver()
        {
            le = ancla;
            Write("La {0} tiene: ", identificacion);
            Write("<-");
            while (le.Sig != null)
            {
                le = le.Sig;
                Write("[" + le.info + "]" + "-");
            }
            Write("|");
            WriteLine();
        }

        public Nodo ObtenerPorIndice(int? indice)
        {
            le = ancla;
            int contador = -1;
            while(le.Sig != null)
            {
                le = le.Sig;
                contador++;
                if (contador == indice)
                {
                    return le;
                }
            }
            return le;
        }

        //public static void Swap<T> (T a, T b)
        //{
        //    T temp = a;
        //    a = b;
        //    b = temp;
        //}

        public int? Indice(int info)
        {
            le = ancla;
            short contador = -1;
            while (le.info != info) {
                le = le.Sig;
                contador++;
                if (le.info == info)
                {
                    return contador;
                }
            }
            return null;
        }

        public int this[int indice]
        {
            get
            {
                Nodo tmp = ObtenerPorIndice(indice);
                return tmp.info;
            }

            set 
            {
                Nodo tmp = ObtenerPorIndice(indice);
                if(tmp != null)
                {
                    tmp.info = value;
                }
            }
        }
    }
}
