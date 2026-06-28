# Estado do Trabalho — TP1

## Camadas implementadas nesta etapa

- **Interfaces** (`interfaces.hpp`): classes abstratas `IU*` (apresentação) e `ILN*`
  (serviço) com métodos virtuais puros, uma por módulo.
- **Camada de serviço**:
  - Contêineres (`containers.hpp/.cpp`) com `list<T>` — incluir/remover/pesquisar/atualizar/listar.
  - Controladoras `CntrLN*` (`controladoras_servico.hpp/.cpp`) com as regras de negócio.
- **Camada de apresentação**: controladoras `CntrIU*`
  (`controladoras_apresentacao.hpp/.cpp`) com interação `cin`/`cout` e validação de entrada.
- **Autenticação**: porta de entrada por email + senha (padrão do Lab 10).
- **`main.cpp`**: roda os testes unitários e, em seguida, o sistema integrado com menu.

## Serviços (dos 25 da especificação)

| Serviço | Situação |
|---|---|
| 1-4 CRUD Pessoa | OK |
| 5-8 CRUD Projeto | OK |
| 9-12 CRUD Plano de Sprint | OK |
| 13-16 CRUD História de Usuário | OK |
| 19 Listar projetos por pessoa | OK |
| 20 Listar histórias por projeto | OK |
| 21 Listar planos por projeto | OK |
| 22 Listar histórias por plano de sprint | OK |
| 24 Mover história para plano de sprint | OK |
| 25 Alterar estado de história | OK |
| 17/18 Associar/remover associação História ↔ Pessoa | OK |
| 23 Listar histórias associadas a pessoa | OK |

**Os 25 serviços da especificação estão implementados.**

## Regras de negócio

- OK: soma das capacidades dos planos ≤ dias entre início e término do projeto.
- OK: soma das estimativas das histórias do sprint ≤ capacidade do plano (ao mover).
- OK: ao criar projeto, exige proprietário com papel PROPRIETARIO DE PRODUTO e mestre MESTRE SCRUM.
- OK: **controle de acesso por papel** (tabela ID SERVIÇO / PAPÉIS da especificação) — cada
  serviço restrito verifica o papel de quem o invoca na camada de serviço e lança "Acesso negado"
  se não autorizado (ex.: só Proprietário cria projeto/história; só Mestre Scrum cria sprint).
- OK: ao criar história, estado é forçado para A FAZER.
- OK: não é possível editar chave primária (email/código) — atualização só altera demais campos.
- PARCIAL: integridade referencial em exclusões (ex.: excluir projeto com planos/histórias
  associados) — remove a entidade e suas associações diretas, mas não bloqueia a exclusão
  para impedir toda inconsistência possível. Refinar conforme as multiplicidades do diagrama.

## Fora do escopo desta etapa de código (a fazer manualmente)

- [ ] Gerar as páginas HTML rodando a ferramenta **Doxygen** (os comentários já estão no código).
- [ ] Desenhar o **diagrama UML** da arquitetura (módulos + interfaces) e exportar em PDF.
- [ ] Gravar o **vídeo** de smoke test.
- [ ] Empacotar o **zip** `T1-TP1-X-Y-Z.ZIP` com matrículas dos autores.

## Como compilar e executar

- Code::Blocks: abrir `ProjetoFinal.cbp` → Build and run (F9).
- Linha de comando (MinGW):
  ```
  g++ -std=c++11 -I. main.cpp dominios/*.cpp entidades/*.cpp testesUnitarios/*.cpp \
      containers.cpp controladoras_servico.cpp controladoras_apresentacao.cpp -o scrum
  ```
- Na tela inicial, escolha **2 - Criar conta** para cadastrar um usuario (qualquer email
  valido), depois **1 - Entrar** para autenticar e acessar os servicos.
