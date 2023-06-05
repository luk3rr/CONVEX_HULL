/*
* Filename: utils.cc
* Created on: May 12, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "utils.h"

namespace utils {
    int Min(int i, int j) {
        if (i < j)
            return i;
        else
            return j;
    }

    int Min(int i, int j, int k, int l) {
        int min1 = utils::Min(i, j);
        int min2 = utils::Min(k, l);

        return utils::Min(min1, min2);
    }

    int Min(int i, int j, int k, int l, int m, int n) {
        int min1 = utils::Min(i, j, k, l);
        int min2 = utils::Min(m, n);

        return utils::Min(min1, min2);
    }

    int Max(int i, int j) {
        if (i > j)
            return i;
        else
            return j;
    }

    int Max(int i, int j, int k) {
        int max1 = utils::Max(i, j);

        return utils::Max(max1, k);
    }

    int Max(int i, int j, int k, int l) {
        int max1 = utils::Max(i, j);
        int max2 = utils::Max(k, l);

        return utils::Max(max1, max2);
    }

    void Usage() {
        std::cout << "FECHO CONVEXO\n" << std::endl;
        std::cout << "  -f, --file <string>   Caminho do arquivo" << std::endl;
        std::cout << "  -r, --random          Gera pontos aleatórios" << std::endl;
        std::cout << "  -p, --points <int>    Número de pontos aleatórios" << std::endl;
        std::cout << "  -g, --graphic         Habilita o modo gráfico" << std::endl;
        std::cout << "  -a, --analyzer        Realiza uma bateria de testes" << std::endl;
        std::cout << "  -h, --help            Mensagem de ajuda" << std::endl;
    }

    void SfmlUsage() {
        std::cout << "\n---------------" << std::endl;
        std::cout << "Modo gráfico ativado\nUSAGE:" << std::endl;
        std::cout << "- Click botão direito do mouse:" << std::endl;
        std::cout << "      Ativa o modo de arrastar a tela (não precisa segurar)" << std::endl;
        std::cout << "      Click novamente para desativar esse modo" << std::endl;
        std::cout << "- Role a roda do mouse para aumentar ou diminuir o zoom" << std::endl;
        std::cout << "- Executar as animações:" << std::endl;
        std::cout << "      Pressione a tecla 'g' para executar a animação do Graham Scan" << std::endl;
        std::cout << "      Pressione a tecla 'j' para executar a animação do Jarvis March" << std::endl;
        std::cout << "- Pressione a tecla 'q' para fechar a janela de animação" << std::endl;
        std::cout << "- DICA:" << std::endl;
        std::cout << "      Enquanto a animação do Graham Scan ou do Jarvis estiver rodando o zoom e o arrasto de tela não funcionam ;-;" << std::endl;
        std::cout << "      Posicione a tela antes de executar as animações" << std::endl;
        std::cout << "---------------" << std::endl;
    }
} // namespace utils
