# Programa para descriptografar imagens do tipo .ppm ou . pgm
=============================================================

##PROPOSTA
O programa serve para ler uma imagem do tipo .ppm ou .pgm e encontrar uma imagem criptografada. Cada tipo de arquivo tem um tipo de criptografia.
Criptografias usadas:
* PGM: cifra de cesar.
* PPM: cifra da palavra-chave.

Ps.: Outras informações: [WIKI - EP1 Professor Renato Sampaio](https://gitlab.com/oofga/eps_2018_1/ep1/wikis/home).


## PRÉ-REQUISITOS (LINUX)
Para poder usar o prgrama, deverá usar os seguintes passos: 
1. Dar git clone do repositório;
2. As fotos devem estar dentro do repositório, como os exemplos;
3. para iniciar o programa, usa-se o seguinte comando 

```
$ make run
```

## FUNCIONAMENTO
Segue como o programa funciona:
1. Após o make run, o programa perguntará qual tipo de imagem o usuário quer descriptografar.
2. escolhendo uma das opções (.pgm ou .ppm), o usuário deve adicionar o nome do arqivo junto com a extensão da imagem escolhida no menu.
    Exemplo:

```
$ exemplo.ppm
```
3. Por fim, será apresentará a mensagem e o programa finalizará.

## IDEALIZADOR
Ésio Gustavo Pereira Freitas - 2018.1.
