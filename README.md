# Batalha
### Jogo de Batalha Naval feito em C  
Depois de ter aprendido um pouco da linguagem C na universidade, tive a ideia de criar esse jogo no final do meu 1º semestre, a fim de aplicar o básico que eu tinha aprendido.  

A versão inicialmente postada (1/6/2021) foi desenvolvida aos poucos, entre nov/2019 - jul/2020, e quando terminei, pelo menos a ideia básica da lógica do jogo já funcionava.

Coloquei o código aqui com o fim de fazer pequenas melhorias no jogo e na organização do código, para ter um controle melhor das mudanças, e ter um primeiro contato mais prático com Git e GitHub.

**Obs: Leia bem o arquivo de instruções antes !!**

**Obs2: O código foi desenvolvido no CodeBlocks v20.03 com o compilador GNU GCC Compiler**

**Obs3:** para quem usa Windows, ao rodar o código a tela abre maximizada, mas se não for o caso, para evitar problemas, basta apenas comentar o trecho `# include <windows.h>` no início do código e o trecho a seguir, localizado logo abaixo da `int main()` do código:
```
{HWND hwnd = GetConsoleWindow();
ShowWindow(hwnd, SW_SHOWMAXIMIZED);}
```

**Edit: como tinha desenvolvido o código usando Windows, não percebi que ele basicamente só funciona bem nesse mesmo SO por conta de alguns comandos system. Com o tempo vou tentar adaptar isso**
