/*
 Author: LUCA DE ALENCAR SALAZAR PRIMO
 Matricula: 733641
*/
// lista de dependencias
#include "myKarel.hpp"

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
    world->set(5, 3, BEEPER);
    world->set(5, 3, BEEPER);
    world->set(5, 3, BEEPER);
    world->set(5, 3, BEEPER);
    world->set(5, 3, BEEPER);
    world->set(5, 3, BEEPER);
    world->save(fileName);
}

int main()
{
    // definir o contexto
    // criar o ambiente
    // OBS.: executar pelo menos uma vez,
    // antes de qualquer outra coisa
    // (depois de criado, podera' ser comentado)
    world->create(""); // criar o mundo
    decorateWorld("Guia01E2.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia01E2.txt"); // ler configuracao atual para o ambiente
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
