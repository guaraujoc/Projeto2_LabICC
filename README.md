# Meu Financiamento

Aluno: Gustavo Carvalho Araújo / 13735630
Aluno: João Pedro Gomes / 13839069

## Descrição

&nbsp;&nbsp;&nbsp;&nbsp; O programa "Meu Financiamento" tem como objetivo facilitar o acesso à informação das características do seu financiamento, mostrando os juros pagos, quantas prestações faltam e as suas novas características a cada amortização realizada. 

&nbsp;&nbsp;&nbsp;&nbsp; O seu funcionamento foi divido em diferentes funções, as quais podem ser adaptadas para diferentes ambientes que necessitam de propriedades avulsas contidas nesse programa. Além disso, foi adaptado para a inclusão de métodos de amortização não convencional de maneira facilitada, permitindo o seu uso em diferentes localidades e sistemas.

## Funcionalidades

O programa oferece as seguintes funcionalidades:

- Identificação do usuário: Permite identificar o usuário do programa, solicitando seu nome e outras informações relevantes.

- Verificação de débitos: Permite verificar se o usuário possui algum débito em aberto.

- Criação de novo financiamento: Permite ao usuário criar um novo financiamento, informando o valor, juros e outras características do empréstimo.

- Cálculo do valor das prestações: Calcula o valor das prestações do financiamento com base nas informações fornecidas.

- Realização de pagamento de uma prestação: Permite ao usuário realizar o pagamento de uma prestação, registrando-o no sistema.

- Amortização SAC: Implementa o método de amortização pela Tabela SAC.

- Amortização SAF: Implementa o método de amortização pela Tabela SAF.

- Amortização SAM: Implementa o método de amortização pela Tabela SAM.

- Abate de dívidas: Permite antecipar pagamentos e verificar a situação do financiamento.

## Utilização

Para utilizar o programa, siga as seguintes etapas:

1. Compile os arquivos de código-fonte e execute o programa.

2. Quando solicitado, informe os dados do usuário, como nome e outras informações relevantes.

3. Verifique se o usuário possui algum débito em aberto. Caso positivo, informe-o e tome as ações necessárias.

4. Crie um novo financiamento, informando o valor, juros e outras características do empréstimo.

5. Calcule o valor das prestações com base nas informações fornecidas.

6. Realize o pagamento de uma prestação, informando o valor pago.

7. Utilize os métodos de amortização (SAC, SAF ou SAM) de acordo com sua preferência.

8. Os dados do usuário, financiamentos e prestações serão salvos em um arquivo.

## Requisitos de Compilação

- Compilador C compatível com o padrão C11 ou superior.

## Estrutura do Projeto

O projeto está estruturado da seguinte maneira:

- O arquivo "main.c" contém a função principal (main) do programa.

- O arquivo "financiamento.h" é um arquivo de header que define as estruturas de dados e protótipos de função utilizados no programa.

- O arquivo "financiamento.c" contém as implementações das funções definidas no arquivo de header "financiamento.h".

- Outros arquivos de código-fonte podem ser adicionados para implementar funcionalidades adicionais.

- O arquivo "Makefile" contém as instruções para compilar o programa.

## Contribuindo

Contribuições são bem-vindas! Se você tiver sugestões, melhorias ou correções, fique à vontade para abrir uma issue ou enviar um pull request.

## Licença

Este programa está licenciado sob a [MIT License](https://opensource.org/licenses/MIT).
