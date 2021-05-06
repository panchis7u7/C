package estructuradedatos;

public class Lista {
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

        public boolean estaVacia() {
            return (ancla == null) ? true : false;
        }

        public void ins(int dato)
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

        public void insInicio(int dato)
        {
            Nodo nuevo = new Nodo(dato);
            nuevo.Sig = ancla.Sig;
            ancla.Sig = nuevo;
        }

        public Nodo buscar(int info)
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

        public void del(int info)
        {
            le = ancla;
            Nodo tmp = le;
            Nodo aux = buscar(info);
            do
            {
                tmp = aux;
                anterior(info).Sig = tmp.Sig;
                tmp.Sig = null;
                tmp = le;
                aux = buscar(info);
            } while ((aux != null) && (estaVacia() != true));
        }

        public Nodo anterior(int info)
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

        public void ver()
        {
            le = ancla;
            System.out.print("La {" + identificacion + "} tiene: ");
            System.out.print("<-");
            while (le.Sig != null)
            {
                le = le.Sig;
                System.out.print("[" + le.info + "]" + "-");
            }
            System.out.print("|");
            System.out.println();
        }

        public Nodo obtenerPorIndice(int indice)
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

//        public static void Swap<T> (T a, T b)
//        {
//            T temp = a;
//            a = b;
//            b = temp;
//        }

        public int indice(int info)
        {
            le = ancla;
            short contador = -1;
            while (le.Sig != null) {
                le = le.Sig;
                contador++;
                if (le.info == info)
                {
                    return contador;
                }
            }
            return -1;
        }

//        public int this[int indice]
//        {
//            get
//            {
//                Nodo tmp = obtenerPorIndice(indice);
//                return tmp.info;
//            }
//
//            set 
//            {
//                Nodo tmp = obtenerPorIndice(indice);
//                if(tmp != null)
//                {
//                    tmp.info = value;
//                }
//            }
//        }
//    }
}
