#include <iostream>
using namespace std;
struct vox{
    char nombreApellido;
    int exp;
    vox *sgt;
};
vox *peek = NULL;
void push(char nA,int num){
    vox *nvox =  new vox;
    nvox->exp=num;
    peek=nvox;
}
void pushChar(){
    vox *nvox =  new vox;
    nvox->nombreApellido=nA;
    peek=nvox;
}
void pop(){
    if(peek==NULL)
        cout<<"Nada que imprimir, Stack vacia \n";
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
            aux=aux->sgt;
        }
}
int main(){
    int op;
    do{
        cout<<"\n(1) Push    (3) Pop    (4) Print   (5) Salir \n ";
        cout<<"\n Elija opcion  ?: ",cin>>op;
        switch (op){
            case 1:
                char nombreAp;
                int numExp;
                cout<<"Ingresa el valor a insertar en el Stack : ??  ",cin>>nombreAp;
                cout<<"Ingresa el valor a insertar en el Stack : ??  ",cin>>numExp;
                push(nombreAp,numExp);
                break;
            case 2:
                cout<<"Eliminando ..... : ";
                pop();
                break;
            case 3:
                cout<<"Imprimiendo..... : ";
                prt();
                break;
            case 4:
                cout<<"------Bye--------";
        }
    }while(op!=4);
}
