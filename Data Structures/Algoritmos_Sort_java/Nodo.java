package estructuradedatos;

public class Nodo {
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

    @Override
        public String toString()
        {
            String imprimir = ("[" + info + "]");
            return imprimir;
        }
}
