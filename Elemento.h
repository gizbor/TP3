#ifndef ELEMENTO_H
#define ELEMENTO_H

class Elemento
{
    public:
        Elemento() {}
        virtual ~Elemento() {}

        virtual void imprimir() {}

        virtual bool operator==(Elemento& e) = 0;

        virtual bool operator>(Elemento& e) = 0;
        virtual bool operator<(Elemento& e) = 0;
    protected:
    private:
};

#endif // ELEMENTO_H
