//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include "fila_substrings.h"
#include "gtest/gtest.h"

using std::string;
using std::to_string;
using std::queue;

static const char SEP[] = ",.;:/|-&%$+=*?";

class TesteEnfileira: public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
    }

    string gen_word() {
        string s;
        int n;

        n = 2 + (rand() % 32);
        while (n-- > 0) s += (char)('a'+(rand() % 26));
        return s;
    }

    char rand_char() {
        return SEP[rand()%(sizeof(SEP)-1)];
    }

    char gen_string(string & s, queue<string> & q) {
        char sep = rand_char();
        string w;

        int j = 2+(rand()%20); // qtde de substrings
        while (j-- > 1) {
            w = gen_word();
            q.push(w);
            s += w;
            s += sep;
        }
        w = gen_word();
        q.push(w);
        s += w;

        return sep;
    }

    string queue2str(queue<string> & q) {
        string r;

        while (! q.empty()) {
            r += q.front() + ' ';
            q.pop();
        }
        return r;
    }

};

/*::testing::AssertionResult AssertSubstitui(const char* texto_expr,
                                               const char* sub_expr,
                                               const char* outra_expr,
                                               const char* correto_expr,
                                               const string & texto,
                                               const string & sub,
                                               const string & outra,
                                               const string & correto) {
    string res = substitui(texto, sub, outra);
    if (res == correto) return ::testing::AssertionSuccess();

    return ::testing::AssertionFailure() << "texto=" << texto << ", " << sub_expr << "=" << sub << ", " << outra_expr << "=" << outra << ": "
                                         << " resultado deveria ser: " << correto
                                         << ", mas sua função retornou: " << res;
}
*/

TEST_F(TesteEnfileira, Vazia) {
    try {
        queue<string> q;
        separa("", rand_char(), q);

        if (q.size() > 0) {
            FAIL() << "queue tem tamanho maior que 0 após enfileirar caracteres de uma string vazia";
        }

    } catch (...) {
        FAIL() << "ocorreu uma exceção";
    }

}

TEST_F(TesteEnfileira, Simples) {
    for (int i=0; i < 10; i++) {
        try {
            queue<string> q;
            string w = gen_word();
            char sep = rand_char();
            separa(w, sep, q);

            if (q.size() != 1) {
                FAIL() << "queue tem tamanho " << q.size() << ", mas deveria ter size 1";
                return;
            }

        } catch (...) {
            FAIL() << "ocorreu uma exceção";
        }
    }
}

TEST_F(TesteEnfileira, Normal) {
    string s;
    char sep;

    try {
        for (int n=0; n < 10; n++) {
            queue<string> q1, q2;
            s = "";
            sep = gen_string(s, q1);
            separa(s, sep, q2);

            if (q1 != q2) {
                FAIL() << "string="+s+" separador="+sep
                       << ", fila esperada: " << queue2str(q1)
                       << ", fila obtida: " << queue2str(q2);
                return;
            }
        }
    } catch (...) {
        string c;
        c += sep;
        FAIL() << "ocorreu uma exceção: string="+s << ">>> sep="+c;
    }
}
