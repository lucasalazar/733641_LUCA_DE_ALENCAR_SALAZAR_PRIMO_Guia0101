/*
 Author: LUCA DE ALENCAR SALAZAR PRIMO
 Matricula: 733641
*/
// lista de dependencias
#include "karel.hpp"
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld(const char *fileName)
{
    // colocar um marcador no mundo
    world->set(4, 4, BEEPER);
    // salvar a configuracao atual do mundo
    world->save(fileName);
} // decorateWorld ( )
/**
 Classe para definir robo particular (MyRobot),
 a partir do modelo generico (Robot)
 Nota: Todas as definicoes irao valer para qualquer outro robo
 criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
public:
    /**
 turnRight - Procedimento para virar 'a direita.
 */
    void turnRight()
    {
        // testar se o robo esta' ativo
        if (checkStatus())
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            turnLeft();
            turnLeft();
            turnLeft();
        } // end if
    }     // end turnRight ( )
    /**
 moveN - Metodo para mover certa quantidade de passos.
 @param steps - passos a serem dados.
 */
    void moveN(int steps)
    {
    // definir dado local
        int step = 0;
    // testar se a quantidade de passos e maior que zero
        for (step = 1; step <= steps; step = step + 1) // outra alternativa
        {
        // dar um passo
            move();
        }//end if
    }     // end moveN( )
    /**
 doPartialTask - Metodo para especificar parte de uma tarefa.
 */
    void doPartialTask()
    {
        // especificar acoes dessa parte da tarefa
        moveN(3);
        turnLeft();
    } // end doPartialTask( )
    /**
 doTask - Relacao de acoes para o robo executar.
 */
    void doTask()
    {
        // especificar acoes da tarefa
        doPartialTask();
        doPartialTask();
        // testar se  ha marcador antes...
        if (nextToABeeper())
        {
            //de tentar carrega-lo
            pickBeeper();
        } // end it
        doPartialTask();
        // testar se carrega marcador antes...
        if (nbeepers() > 0)
        {
            // ... de tentar descarrega-lo
            putBeeper(); // colocar marcador
        }                // end it
        doPartialTask();
        turnLeft();
        // encerrar
        turnOff();
    } // end doTask( )
};    // end class MyRobot
// --------------------------- acao principal
/**
 Acao principal: executar a tarefa descrita acima.
*/
int main()
{
    // definir o contexto
    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    // antes de qualquer outra coisa
    // (depois de criado, podera' ser comentado)
    world->create(""); // criar o mundo
    decorateWorld("Guia0110.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0110.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(3);                // definir velocidade padrao
                                 // criar robo
    MyRobot *robot = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 0, "Karel");
    // executar tarefa
    robot->doTask();
    // encerrar operacoes no ambiente
    world->close();
    // encerrar programa
    getchar();
    return (0);
} // end main ( )
// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
V 1.0; Teste 0.1
Função : for (step = 1; step < steps; step = step +1)
Desse modo o robo fara uma volta menor, e nao passara pelos marcadores.

V 1.0; Teste 0.2
Função : for (step = 1; step <= steps; step = step +1)
Desses modo o robo fara uma volta passando pelos marcados.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
 0.1 0.1 ( OK ) teste inicial
 0.2 0.1 ( OK ) teste da tarefa
 0.3 0.1 ( OK ) teste da tarefa parcial
 0.4 0.1 ( OK ) teste do apanhar marcador
 0.5 0.1 ( OK ) teste do colocar marcador
 0.6 01. ( OK ) teste da repeticao do movimento
 0.7 01. ( OK ) teste com marcador na posicao (4,4)
     02. ( OK ) teste sem marcador na posicao (4,4)
 0.8 01. ( OK ) teste como a quantidade de marcadores 
 0.9 01. ( OK ) teste com outra forma de repeticao
 0.10 01.( OK ) teste com outra forma de alternativa
*/