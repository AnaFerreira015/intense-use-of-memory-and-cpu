# Identificação

* Página do repositório do trabalho ([link GitHub](TODO)) 

* Discente 1
	* Nome: Ana Lúcia da Silva Ferreira
	* Matrícula: 18110600 
	* Distribuição da nota (%): TODO
* Discente 2
	* Nome: Letícia Melquíades dos Santos Medeiros
	* Matrícula: 18110472
	* Distribuição da nota (%): TODO
* Discente 3
	* Nome: Kelly Bianca Araújo Silva
	* Matrícula: 18112705
	* Distribuição da nota (%): TODO		
	
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
![Uso de UCP com o comando usleep](https://github.com/AnaFerreira015/intense-use-of-memory-and-cpu/blob/master/img/ucp.png)


##Utilização intensa da UCP e Memória


## Utilização intensa da UCP e memória

TODO: explicar se o comportamento da curva **UCP-MEM** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.
