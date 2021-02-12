package estructuradedatos;

import java.util.Scanner;

public class AppEstructuradeDatos {
    private static Lista lista1 = new Lista("1ista1");
    public static void main(String[] args) {
        Scanner flujo = new Scanner(System.in);
        lista1.ins(5);
        lista1.ins(6);
        lista1.ins(6);
        lista1.ins(4);
        lista1.insInicio(8);
        lista1.insInicio(10);
        lista1.insInicio(6);
        lista1.ins(2);
        lista1.insInicio(2);
        lista1.ver();
        Nodo Encontrado = lista1.buscar(2);
        System.out.println("\nBusqueda de nodo con info " + Encontrado.info + ": " + Encontrado);
        Nodo anterior = lista1.anterior(8);
        System.out.println("Anterior de nodo con info " + anterior.info + ": " + anterior + "\n");
//      System.out.println("Nodo con indice: " + Pila1[3]); Solo en c#
//      Pila1[3] = 55; Solo en c#
        lista1.ver();
        lista1.del(6);
        lista1.ver();
        
        System.out.println("\nLista de algoritmos para sortear la lista enlazada:");
        System.out.println("1.- Bubble Sort");
        System.out.println("2.- Insertion Sort (Version inline)");
        System.out.println("3.- Selection Sort (Version inline)");
        System.out.println("4.- Merge Sort");
        System.out.println("5.- Quick Sort");
        
        int desicion = flujo.nextInt();
        int cantidad = lista1.Cantidad();
        switch (desicion) {
            
        case 1:
        //Bubble Sort
            System.out.println("Bubble Sort");
        for (int i = 1; i < cantidad; i++)
        {
            for (int j = 0; j < cantidad-i; j++)
            {
                if(lista1.obtenerPorIndice(j).info > lista1.obtenerPorIndice(j+1).info)
                {
                    swap(j, j + 1);
                }
            }
        }
        lista1.ver();
        break;
        
        case 2:
             //Insertion Sort version Inline
                    System.out.println("Insertion Sort");
                    int posAgujero = 0;
           
                    for (int i = 1; i < cantidad; i++)
                    {
                        posAgujero = i;
                        while (posAgujero > 0 && lista1.obtenerPorIndice(posAgujero).info < lista1.obtenerPorIndice(posAgujero - 1).info)
                        {
                            swap(posAgujero, posAgujero-1);
                            posAgujero = posAgujero - 1;
                        }
                    }
                    lista1.ver();
                    break;

                case 3:
                    //Selection Sort version inline
                    System.out.println("Selection Sort");
                    int indiceMenor = 0;
                    for (int i = 0; i < cantidad-1; i++)
                    {
                        indiceMenor = i;
                        for (int j = i + 1; j < cantidad; j++)
                        {
                            if (lista1.obtenerPorIndice(j).info < lista1.obtenerPorIndice(indiceMenor).info)
                                indiceMenor = j;
                        }
                        swap(i, indiceMenor);
                    }
                    lista1.ver();
                    break;

                case 4:
                    //Merge Sort
                    System.out.println("Merge Sort");
                    Lista lista2 = mergeSort(lista1);
                    lista2.ver();
                    break;

                case 5:
                    //Quick Sort
                    System.out.println("Quick Sort");
                    quickSort(0, lista1.Cantidad() - 1);
                    lista1.ver();
                    break;

                default:
                    break;
            }
    }
    
        public static void quickSort(int inicio, int fin)
        {
            int iPivote = 0;
            if (inicio >= fin)
                return;
            iPivote = particion(inicio, fin);

            //Casos inductivos
            quickSort(inicio, iPivote - 1);
            quickSort(iPivote + 1, fin);
        }
        
        public static int particion(int inicio, int fin)
        {
            int pivote;
            int iPivote;
            //Se selecciona el ultimo elemento como pivote
            pivote = lista1.obtenerPorIndice(fin).info;
            //Ponemos el indice del pivote como el primer elemento
            iPivote = inicio;
            for (int n = inicio; n < fin; n++)
            {
                if(lista1.obtenerPorIndice(n).info <= pivote)
                {
                    swap(n, iPivote);
                    iPivote++;
                }
            }
            swap(iPivote, fin);
            return iPivote;
        }
        
        public static Lista merge (Lista listaIzq, Lista listaDer)
        {
            Lista union = new Lista("Union");
            int indiceIzq = 0;
            int indiceDer = 0;
            int cantidadIzq = listaIzq.Cantidad();
            int cantidadDer = listaDer.Cantidad();
            //Recorremos mientras las dos listas tengan elementos son procesar
            while (indiceIzq < cantidadIzq && indiceDer < cantidadDer)
            {
                if(listaIzq.obtenerPorIndice(indiceIzq).info <=  listaDer.obtenerPorIndice(indiceDer).info)
                {
                    union.ins(listaIzq.obtenerPorIndice(indiceIzq).info);
                    indiceIzq++;
                } else
                {
                    union.ins(listaDer.obtenerPorIndice(indiceDer).info);
                    indiceDer++;
                }
            }

            while(indiceIzq < cantidadIzq)
            {
                union.ins(listaIzq.obtenerPorIndice(indiceIzq).info);
                indiceIzq++;
            }

            while (indiceDer < cantidadDer)
            {
                union.ins(listaDer.obtenerPorIndice(indiceDer).info);
                indiceDer++;
            }
            return union;
        }

        public static Lista mergeSort(Lista lista)
        {
            int cantidad = lista.Cantidad();

            if (cantidad < 2)
                return lista;

            //Punto Medio
            int mitad = cantidad / 2;

            Lista izq = new Lista("ListaIzq");
            Lista der = new Lista("ListaDer");
            for (int n = 0; n < mitad; n++)
                izq.ins(lista.obtenerPorIndice(n).info);

            for (int n = mitad; n < cantidad; n++)
                der.ins(lista.obtenerPorIndice(n).info);

            //Casos inductivos
            Lista tmpI = mergeSort(izq);
            Lista tmpD = mergeSort(der);
            Lista ordenada = merge(tmpI, tmpD);

            return ordenada;
        }
    
    private static void swap(int i1, int i2)
        {
        int temp = lista1.obtenerPorIndice(i1).info;
        lista1.obtenerPorIndice(i1).info = lista1.obtenerPorIndice(i2).info;
        lista1.obtenerPorIndice(i2).info = temp;
        }
    }
