/*
 Author: LUCA DE ALENCAR SALAZAR PRIMO
 Matricula: 733641
*/
// lista de dependencias
#include "karel.hpp"

void decorateWorld(const char *filename)
{
    world->save(filename);
}

class MyRobot : public Robot
{
public:
    void moveN(int steps)
    {
        // definir dado local
        int step = 0;
        // testar se a quantidade de passos e maior que zero
        for (step = 1; step <= steps; step = step + 1) // outra alternativa
        {
            // dar um passo
            move();
        } //end if

    } // end moveN( )

    void repeatN(int n)
    {
        turnLeft();
        moveN(n);
    }
    void turnRight()
    {
        if (checkStatus())
        {
            turnLeft();
            turnLeft();
            turnLeft();
        }
    }
    void doTask()
    {
        // se posicionar no primeiro ponto
        moveN(2);
        repeatN(2);
        // testar se carrega marcador antes...
        if (nbeepers() > 0)
        {
            // ... de tentar descarrega-lo
            putBeeper(); // colocar marcador
        }                // end it
        // ir ao proximo ponto
        turnRight();
        moveN(3);
        if (nbeepers() > 0)
        {
            // ... de tentar descarrega-lo
            putBeeper(); // colocar marcador
        }
        // ir ao proximo ponto
        repeatN(3);
        if (nbeepers() > 0)
        {
            // ... de tentar descarrega-lo
            putBeeper(); // colocar marcador
        }
        //voltar ao inicio
        repeatN(5);
        repeatN(5);
        //virar pro leste
        turnLeft();
        // encerrar
        turnOff();
    } // end doTask( )
};

int main()
{
    // definir o contexto
    // criar o ambiente
    // OBS.: executar pelo menos uma vez,
    // antes de qualquer outra coisa
    // (depois de criado, podera' ser comentado)
    world->create(""); // criar o mundo
    decorateWorld("Guia0111.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0111.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(3);                // definir velocidade padrao
                                 // criar robo
    MyRobot *robot = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 3, "Karel");

    robot->doTask();
    // encerrar operacoes no ambiente
    world->close();
    // encerrar programa
    getchar();
    return (0);
} // end main ( )
