programa {
  funcao inicio() {
    inteiro poltrona[5][6]
    inteiro filaComprada, poltronaComprada

    para(inteiro linha = 0; linha < 5; linha++) {
      para (inteiro coluna = 0; coluna < 6; coluna++) {
        poltrona[linha][coluna] = 0
      }
    }

    escreva("Mapa do Teatro\n")
    escreva("\n--------------------------------------------- # PALCO # -----------------------------------------\n")

    para(inteiro linha = 0; linha < 5; linha ++) {
      escreva("\n")
      para(inteiro coluna = 0; coluna < 6; coluna++) {
        escreva("P(", linha, coluna, "): ", poltrona[linha][coluna], " | ")
      } 
    }
    
    escreva("\n")
    escreva("\n--------------------------------------- # FIM DO TEATRO # ---------------------------------------\n\n")

    escreva("Digite o número da fila em que deseja comprar a poltrona: ")
    leia(filaComprada)

    escreva("Digite o número da poltrona que deseja comprar: ")
    leia(poltronaComprada)

    poltrona[filaComprada][poltronaComprada] = -1

    escreva("\n--------------------------------------------- # PALCO # -----------------------------------------\n")

    para(inteiro linha = 0; linha < 5; linha ++) {
      escreva("\n")
      para(inteiro coluna = 0; coluna < 6; coluna++) {
        se (poltrona[linha][coluna] == -1) {
          escreva(" * * * * | ")  
        } senao {
          escreva("P(", linha, coluna, "): ", poltrona[linha][coluna], " | ")
        }
      } 
    }
    
    escreva("\n")
    escreva("\n--------------------------------------- # FIM DO TEATRO # ---------------------------------------\n\n")

  }
}
