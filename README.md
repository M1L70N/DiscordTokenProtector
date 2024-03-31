# Discord Token Protector
#### Proteja seu token do Discord contra capturadores maliciosos!

## [Para os espectadores do NTTS, aqui está minha resposta ao vídeo.](NTTS.md)

##### ✔️ **Funciona com a versão mais recente do Discord.**

![Main Workflow](https://github.com/andro2157/DiscordTokenProtector/actions/workflows/msbuild.yml/badge.svg)

<p align="center">
  <img width="500" src="Assets/DiscordTokenProtectorUI.png">
</p>

Este projeto ainda está em desenvolvimento! Você pode enfrentar alguns problemas de instabilidade!\
Esta **NÃO** é de forma alguma uma solução perfeita contra capturadores de tokens do Discord.
Mas isso vai te proteger contra a maioria dos capturadores de tokens:
- (Mais comum) Leitura do LevelDB *(desde o início)*
- (Menos comum) Injeção de script / Manipulação do módulo do Discord *(a partir de dev-6)*
- (Raro) Leitura de memória *(a partir de dev-8)*

**Qualquer ataque direcionado contra o DiscordTokenProtector pode contornar essa proteção!**

## [✔️Práticas recomendadas ao usar o DiscordTokenProtector (DTP)](goodpractice.md)

### ⚠️ Aviso Legal
**O DTP não possui afiliação com o Discord.**\
**O DTP não se responsabiliza de forma alguma pelo que pode acontecer em sua conta do Discord.**\
**As chances de ser banido ao usar o DTP são muito baixas, mas por favor, tenha em mente que o uso de software de terceiros é contra os Termos de Serviço do Discord.**


## Recursos

#### ✅ Proteja-se contra a maioria dos capturadores de tokens
#### ✅ Armazene seu token do Discord de forma segura em um arquivo criptografado (YubiKeys* são suportados)
#### ✅ Troque facilmente entre várias contas
#### ✅ Altere sua senha do Discord com um clique
#### ✅ Verifique a integridade da sua instalação do Discord ao iniciar (BetterDiscord é suportado)
#### ✅ Verifique scripts em busca de malwares conhecidos *(por exemplo, AnarchyGrabber3)*
#### ✅ Proteja o processo do Discord contra leitura de memória / injeção de código
#### ✅ Proteja o DTP contra ataques de manipulação (protege o processo/configuração contra usuários não autorizados)

**Exceto pelo YubiKey NEO*

## 
Instalação / Atualização

### Baixe a versão mais recente. **[HERE](https://github.com/andro2157/DiscordTokenProtector/releases)**

* Inicie o DiscordTokenProtectorSetup.exe
* Selecione entre a instalação Normal e Sem Inicialização
* **[Configure-o](Setup.md)**
* ([Guia de Configuração do YubiKey](YubiSetup.md))
* Aproveite!

## O que o DiscordTokenProtector faz?

Aqui está um pequeno diagrama de como funciona:

<p align="center">
  <img width="800" src="Assets/how_does_it_work.jpg">
</p>


* Ele remove os diretórios Local Storage e Session Storage de %appdata%\Discord.
Esses diretórios podem armazenar seu token do Discord (usado para autenticá-lo).
A maioria dos capturadores procura pelo seu token lá. Portanto, removendo esses diretórios, você pode evitar que ele seja capturado.
Seu token do Discord é armazenado em um contêiner seguro criptografado com AES-256.

## Algumas coisas a considerar:

* Ao remover esses diretórios, o Discord não pode armazenar nenhuma configuração local.
Isso significa que todas as configurações específicas do cliente serão removidas cada vez que você iniciar o Discord (por exemplo, atalhos de teclado, dispositivo de áudio padrão, ...).
MAS, todas as configurações do lado do servidor ainda são salvas (descrições de usuários, idioma, modo escuro, ...).

* O Discord Canary pode não funcionar corretamente. Essas versões não suportam login de passagem.

* Novamente, este é um projeto em desenvolvimento e você pode encontrar algumas instabilidades (crash, Discord não iniciando, ...). Por favor, relate esses problemas neste repositório.

* Alguns antivírus sinalizam o DiscordTokenProtector porque ele pode iniciar com o Windows e injetar payload no Discord.
Essas atividades são suspeitas para os AVs. Eu forneci versões sem inicialização automática, o que reduz a quantidade de sinalizações falsas.

* O DiscordTokenProtector parece não funcionar bem no Windows 7.

* A verificação de integridade dos hashes é feita manualmente, portanto, você pode receber uma mensagem de erro dizendo que não é possível obter os hashes. Por favor, abra um ticket se isso acontecer!

## Créditos

* [Discord](https://discord.com/)
* Ocornut for [ImGui](https://github.com/ocornut/imgui)
* Nlohmann for the [JSON lib](https://github.com/nlohmann/json)
* [CryptoPP](https://www.cryptopp.com/)
* Stevemk14ebr for [Polyhook v2](https://github.com/stevemk14ebr/PolyHook_2_0)
* [CUrl](https://curl.se/)
* [Yubico](https://www.yubico.com/) for YubiKeys and [yubico-piv-tool](https://github.com/Yubico/yubico-piv-tool)

## Donation

Se você gostaria de apoiar este projeto fazendo uma doação, você pode fazer isso através de:
* [Brave Browser](https://brave.com/) tips
* Crypto (ETH / BSC) 0x6997878c19ab249AEbc523635f09B95b793AfA5D
