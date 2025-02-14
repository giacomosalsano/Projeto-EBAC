# 🛠️ Checklist de Testes do Registro de Nomes da EBAC

## Legenda
1. ✅ - Passou no teste;
2. ❌ - Não passou no teste;
3. ❗️ - Ainda não foi testado



## 🔐 Testes de Login
1. **Login com senha correta** → Deve permitir o acesso ao menu.  
Status do Teste: ✅

2. **Login com senha incorreta** → Deve exibir a mensagem `"Senha Inválida!"` e pedir uma nova tentativa.  
Status do Teste: ✅

3. **Cancelar tentativa de login** → Se o usuário escolher não tentar novamente, o programa deve ser encerrado.  
Status do Teste: ✅



## 📋 Testes de Menu
4. **Exibição do menu principal** → O menu deve aparecer corretamente após o login.  
Status do Teste: ✅

5. **Selecionar opção válida** → Cada opção do menu deve levar à função correspondente.  
Status do Teste: ✅

6. **Selecionar opção inválida** → Deve exibir `"Opção inválida!"` e permitir nova escolha.  
Status do Teste: ✅



## 👤 Testes de Registro de Usuário
7. **Registrar usuário corretamente** → Deve armazenar o nome corretamente. 
Status do Teste: ✅

8. **Registrar usuário com nome vazio** → Deve impedir o registro.  
Status do Teste: ❌

9. **Registrar usuário duplicado** → Se já existir, deve exibir uma mensagem de erro.  
Status do Teste: ✅



## 🔍 Testes de Consulta de Usuário
10. **Consultar um usuário existente** → Deve exibir os dados corretos. 
Status do Teste: ✅

11. **Consultar um usuário inexistente** → Deve exibir uma mensagem de erro. 
Status do Teste: ✅



## ❌ Testes de Deleção de Usuário
12. **Deletar um usuário existente** → Deve remover corretamente e confirmar a ação.  
Status do Teste: ✅

13. **Deletar um usuário inexistente** → Deve exibir uma mensagem de erro.  
Status do Teste: ✅



## 🚪 Testes de Saída do Programa
14. **Selecionar opção de saída no menu** → O programa deve ser encerrado corretamente.  
Status do Teste: ✅

15. **Fechar o programa após falha no login** → Se o usuário escolher `"Não"` ao errar a senha, o programa deve encerrar.
Status do Teste: ✅

