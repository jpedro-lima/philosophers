## The dining Philosophers
Em ciência da computação, [The Dining Philosopher Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) é um exemplo de problema frequentemente usado no design de algoritmos simultâneos para ilustrar problemas de sincronização e técnicas para resolvê-los.

Cinco filósofos estão sentados em uma mesa redonda para jantar. Cada filósofo tem um prato com espaguete à sua frente. Cada prato possui um garfo para pegar o espaguete. O espaguete está muito escorregadio e, para que um filósofo consiga comer, será necessário utilizar dois garfos.

Quando um filósofo fica com fome, ele tenta pegar os garfos à sua esquerda e à sua direita; um de cada vez, independente da ordem. Caso ele consiga pegar dois garfos, ele come durante um determinado tempo e depois recoloca os garfos na mesa. Em seguida ele dorme, e depois volta a pensar.

## A simulação do jantar 
`"I never thought philosophy would be so deadly"`

Este projeto é uma simulação do jantar dos filósofos, onde foram usados uma thread para cara filósofo, e um mutex para cada garfo. Os filósofos (as threads) travam o uso dos garfos com mutex, impedindo outro filósofo (outra thread) de pegar o garfo e começar a comer.

Também foi criado outra rotina de execução com a função de monitorar o jantar, e caso algum filósofo fique um determinado espaço de tempo sem comer, este filósofo morre de fome e a simulação termina.

## Como executar
```bash
$ git clone https://github.com/jpedro-lima/philosophers.git && cd ./philosophers/philo
$ make
$ ./philo 3 800 200 200 5 (exemplo)
```
### Os argumentos
- número de filósofos (limite de um inteiro)
- espaço de tempo onde o filósofo deve comer (milissegundos)
- duração da refeição (milissegundos)
- duração do sono (milissegundos)
- limite de refeições (argumento opcional e no limite de um inteiro)

<div>
<img src="/readme_files/simulation.gif">
</div>

O projeto é atualizado regularmente com correções de bugs e otimização de código.
