// implemente aqui sua função

#include "fila_substrings.h"

void separa(string algo, char sep, queue<string> & q){
    if (!algo.empty()){
        size_t agora , anterior = 0;
        agora = algo.find(sep);
         while (agora!=algo.npos)
            {
             q.push(algo.substr(anterior,agora-anterior));
             anterior=agora+1;
             agora = algo.find(sep,anterior);
            }
        q.push(algo.substr(anterior,agora-anterior));
    }
}