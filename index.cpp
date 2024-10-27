#include <iostream>

struct No{
  No *prox;
  int dado;
};

void Inserir(No **head, int dado){
    No *novo = new No;
    novo->dado = dado;
    if(*head == nullptr){
        *head = novo;
        novo->prox = nullptr;
    }else{
        novo->prox = *head;
        *head = novo;
    }
}

void Remover(No *&head, int chave){
    No *atual = head;
    No *anterior = nullptr;
    
    if(head == nullptr){
        std::cout << "A lista está vazia!" << std::endl;
        return;
    }
    
    if(head->dado == chave){
        No *temp = head;
        head = head->prox;
        delete temp;
        return;
    }
    
    while(atual!=nullptr && atual->dado != chave){
        anterior = atual;
        atual = atual->prox;
    }
    
    if(atual == nullptr){
        std::cout << "Valor não encontrado!" << std::endl;
    }
    
    anterior->prox = atual->prox;
    delete atual;
}

void Imprimir(No *head){
    No *atual = head;
    while(atual!=nullptr){
        std::cout << atual->dado << " ";
        atual = atual->prox;
        std::cout << std::endl;
    }
}

void LiberaLista(No *&head){
    while(head!=nullptr){
        No *temp = head;
        head = head->prox;
        delete temp;
    }
}


int main()
{
    No *head = nullptr;
    int escolha;
    int valorRemover;
    int numInserir;
    
    while(true){
        std::cout << "1 - Inserir, 2 - Remover, 3 - Imprimir, 4 - Sair: ";
        std::cin >> escolha;
        
        switch(escolha){
            case 1:
                std::cout << "Informe o número a ser inserido: ";
                std::cin >> numInserir;
                Inserir(&head, numInserir);
                break;
            case 2:
                std::cout << "Informe o valor que deseja remover: ";
                std::cin >> valorRemover;
                Remover(head, valorRemover);
                break;
                
            case 3:
                Imprimir(head);
                break;
            case 4:
                return 0;
        }
    }
    LiberaLista(head);
    return 0;
}
