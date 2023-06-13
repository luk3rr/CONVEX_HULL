# CONVEX_HULL
CONVEX_HULL é um programa que recebe um conjunto de pontos no plano é retorna o seu fecho convexo.
Esse programa é o produto de uma atividade prática da disciplina de Estruturas de Dados do [Departamento de Ciência da Computação da UFMG](https://dcc.ufmg.br/).

## Sumário
- [Compilação](#Compilação)
- [Execução](#Execução)
- [Documentação](#Documentação)

# Compilação
CONVEX_HULL pode ser compilado com o seguinte comando:

``` sh
$ make build
```

# Execução
Para executar o programa, há duas opções:

- Execução com passagem de parâmetro: ``make run ARGS="<params>"``. Os parâmetros disponíveis seguem abaixo:

| Parâmetro               | Descrição                                 |
|-------------------------|-------------------------------------------|
| `-f, --file <string>`   | Caminho do arquivo                        |
| `-r, --random`          | Gera pontos aleatórios                    |
| `-p, --points <int>`    | Número de pontos aleatórios               |
| `-g, --graphic`         | Habilita o modo gráfico                   |
| `-a, --analyzer`        | Realiza uma bateria de testes             |
| `-h, --help`            | Mensagem de ajuda                         |

- Execução sem passagem de parâmetro: ``make run``
    1. O programa será iniciado e aguardará o caminho do arquivo com o conjunto de pontos
        1. Esse caminho pode ser passado digitando ``fecho caminho/entradas.txt`` ou somente ``caminho/entradas.txt``
    2. A execução sem parâmetro pode ser agilizada quando houver disponível um arquivo de texto de forma que cada linha desse arquivo contenha o caminho de um arquivo com as entradas. Dessa forma, você pode simplesmente utilizar o operador de direcionamento dos sistemas Unix da seguinte maneira: ``make run < caminho/todas_as_entradas.txt``

OBS.: O arquivo de entrada de pontos deve estar estruturado de forma que cada linha tenha a coordenada x e y do ponto, separadas por um espaço em branco. Veja alguns exemplos em [tests/inputs](https://github.com/luk3rr/CONVEX_HULL/tree/main/tests/inputs).

# Documentação
A primeira versão da documentação bem como o enunciado desse trabalho pode ser lida [aqui](https://github.com/luk3rr/CONVEX_HULL/tree/main/docs).
