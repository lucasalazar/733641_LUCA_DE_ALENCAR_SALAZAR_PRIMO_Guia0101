#include "karel.hpp"

void decorateWorld(const char *fileName)
{
    //Limites Horinzontais
    world->set(3, 6, HWALL);
    world->set(4, 6, HWALL);
    world->set(5, 6, HWALL);
    world->set(3, 2, HWALL);
    world->set(4, 2, HWALL);
    world->set(5, 2, HWALL);
    //Limites Verticais
    world->set(2, 3, VWALL);
    world->set(2, 4, VWALL);
    world->set(2, 5, VWALL);
    world->set(2, 6, VWALL);
    world->set(5, 3, VWALL);
    world->set(5, 4, VWALL);
    world->set(5, 5, VWALL);
    //beepers
    world->set(5, 2, BEEPER);
    world->set(5, 7, BEEPER);
    world->set(2, 6, BEEPER);
    world->save(fileName);
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
        // ir ao primeiro ponto
        moveN(4);
        turnLeft();
        moveN(1);
        // se estiver proximo de um beeper pegar ele
        if(nextToABeeper()){
            pickBeeper();
        }
        // ir ao proximo ponto
        turnLeft();
        moveN(3);
        turnRight();
        moveN(3);
        // se estiver proximo de um beeper pegar ele
        if(nextToABeeper()){
            pickBeeper();
        }
        // ir ao proximo ponto
        moveN(1);
        turnRight();
        moveN(3);
        // se estiver proximo de um beeper pegar ele
        if(nextToABeeper()){
            pickBeeper();
        }
        //ir ao ponto de despache
        move();
        turnRight();
        moveN(1);
        turnRight();
        move();
        turnLeft();
        moveN(2);
        while (nbeepers()>0)
        {
            putBeeper();
        }
        
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
    decorateWorld("Guia0114.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0114.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(3);                // definir velocidade padrao
                                 // criar robo
    MyRobot *robot = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 0, "Karel");

    robot->doTask();
    // encerrar operacoes no ambiente
    world->close();
    // encerrar programa
    getchar();
    return (0);
} // end main ( )
