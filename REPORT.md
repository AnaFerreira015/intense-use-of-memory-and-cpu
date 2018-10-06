# Identificação

* Página do repositório do trabalho ([link GitHub](https://github.com/AnaFerreira015/intense-use-of-memory-and-cpu/blob/master/REPORT.md))

* Discente 1
	* Nome: Ana Lúcia da Silva Ferreira
	* Matrícula: 18110600 
* Discente 2
	* Nome: Letícia Melquíades dos Santos Medeiros
	* Matrícula: 18110472
* Discente 3
	* Nome: Kelly Bianca Araújo Silva
	* Matrícula: 18112705
	
* A distribuição da nota será feita de forma igualitária entre as componentes.	
	
# Resultados

## Uso intenso da UCP

* Com o objetivo de fazer a UCP funcionar de forma intensa, utilizamos o comando seguinte:
```
for (;;) {}
```
Que consiste em um loop infinito, dessa forma, essa repetição só é interrompida com o comando que mata o processo pai:
````
  system(kill_process);
````
finalizando, consequentemente, o filho. 

![Uso de UCP](https://github.com/AnaFerreira015/intense-use-of-memory-and-cpu/blob/master/img/ucp.png)

Essa foi então a forma escolhida por nossa equipe para ficar como forma definitiva do nosso programa pois resultou no funcionamento esperado por nós, mas vale ressaltar que durante nossos testes iniciais utilizamos uma estrutura do laço infinito que continha a seguinte estrutura :
````
	for(;;)
  			{
          // usleep(100);
  			}
````
Dessa forma, esse comando ocasionava também o funcionamento da UCP, porém, não de forma intensa, mas sim, um funcionamento moderado, que pode ser observado no gráfio a seguir:

![Uso de UCP com o comando usleep](https://github.com/AnaFerreira015/intense-use-of-memory-and-cpu/blob/master/img/ucp-usleep.png?raw=true)


## Utilização intensa da UCP e Memória

* Para obter o resultado da UCP em funcionamento intenso simultanemanete me conjunto com a Memória foi um desafio e a forma encontrada por nossa equipe foi a utilização do comando:
````
  Clock();
````
Com ele nós utilizamos a lógica de calcular o tempo antes do programa entrar em laço infinito e logo após entrar no mesmo, a diferença desses dois valores foi então comparada a 10.000 e a cada vez que essa condição fosse satisfeita o programa alocava memória, podendo ser observada a seguir:
````
 clock_t start_t, end_t, total_t;
        start_t = clock(); // start to cont clock
  			for(;;)
  			{
          end_t = clock(); // end o clock
          total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
          if(total_t <= 10000)
          {
            	malloc(15*sizeof(int));
          }
  			}
  		}
````
Com a observação do comportamento do programa com essa estrutura de aloação dinâmica pudemos elaborar o seguinte gráfico:

![Uso de UCP e MEM](https://github.com/AnaFerreira015/intense-use-of-memory-and-cpu/blob/master/img/ucp-mem.png)

Mais uma vez essa foi a forma escolhida por nós que mais se aproximou da funcionamento esperado por nós, mas o caminho até essa decisão foi longo, a estrutura inical criada por nós foi a seguinte:
````
for(;;)
  {
  	malloc(10*sizeof(int));
        usleep(1000);
  }
````
Porém, observamos que essa estrutura não nos proprocionava o funcionamento intenso da Memória, mas apenas o da UCP, sendo então descartados por nós.

## Dicursão

* Nossa equipe chegou à presente definição do código (https://github.com/AnaFerreira015/intense-use-of-memory-and-cpu/blob/master/src/main.c) pois analizamos os resultados que foram consisos e de acordo com o solicitado pelo professor, depois de muita pesquisa conseguimos consertar os bugs e o total funcionamento do programa de monitoramento de uso da UCP e Memória.
