#include <iostream>
using namespace std;
struct fecha{
    int dia;
    int mes;
    int ano;
};
struct vox{
    char nombreApellido;
    int exp;
    fecha fecha;
    vox *sgt;
};
vox *peek = NULL;
void pushInt(int num){
    vox *nvox =  new vox;
    nvox->exp=num;
    nvox->sgt=peek;
    peek=nvox;
}
void pushChar(char nA){
    vox *nvox =  new vox;
    nvox->nombreApellido=nA;
    nvox->sgt=peek;
    peek=nvox;
}
void pushFecha(fecha f){
    vox *nvox =  new vox;
    nvox->fecha=f;
    nvox->sgt=peek;
    peek=nvox;
}
void pop(){
    if(peek==NULL)
        cout<<"Nada que sacar, Stack vacia \n";
    else
        peek=peek->sgt;
}
void prt(){
    vox *aux = peek;
    if(aux==NULL)
        cout<<"Nada que imprimir, Stack vacia\n";
    else
        while(aux!=NULL){
            cout<<aux->nombreApellido<<"-";
            cout<<aux->exp<<"-";
            /*cout<<aux->fecha<<"-";*/
            aux=aux->sgt;
        }
}
int main(){
    int op;
    do{
        cout<<"\n(1)PushChar (2)PushInt (3)PushFecha (4)Pop (5)Print (6) Salir \n ";
        cout<<"\n Elija opcion  ?: ",cin>>op;
        switch (op){
            case 1:
                char nombreAp;
                cout<<"Ingresa el char a insertar en el Stack : ??  ",cin>>nombreAp;
                pushChar(nombreAp);
                break;
            case 2:
                int numExp;
                cout<<"Ingresa el entero a insertar en el Stack : ??  ",cin>>numExp;
                pushInt(numExp);
                break;
            case 3:
                int d,m,a;
                fecha f;
                cout<<"Ingresa el dia a insertar en fecha : ??  ",cin>>d;
                cout<<"Ingresa el dia a insertar en fecha : ??  ",cin>>m;
                cout<<"Ingresa el dia a insertar en fecha : ??  ",cin>>a;
                f={d,m,a};
                pushFecha(f);
                break;
            case 4:
                cout<<"Eliminando ..... : ";
                pop();
                break;
            case 5:
                cout<<"Imprimiendo..... : ";
                prt();
                break;
            case 6:
                cout<<"------Bye--------";
        }
    }while(op!=6);
}
