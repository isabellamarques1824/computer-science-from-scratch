# Lógica Proposicional

Aprendi os principais conceitos de lógica proposicional aplicados à Matemática Discreta e à programação.

## Conceitos estudados

- **Proposição:** afirmação que pode ser verdadeira (`V`) ou falsa (`F`).
- **Negação:** `¬p`
- **Conjunção:** `p ∧ q`
- **Disjunção:** `p ∨ q`
- **Implicação:** `p → q`
- **Bicondicional:** `p ↔ q`
- **Expressões proposicionais:** combinação de proposições e operadores lógicos.
- **Tabelas-verdade:** análise das possíveis combinações de valores lógicos.
- **Equivalência lógica:** expressões diferentes que possuem o mesmo resultado.

### Equivalência

`p → q ≡ ¬p ∨ q`

### Leis de De Morgan

`¬(p ∧ q) ≡ ¬p ∨ ¬q`

`¬(p ∨ q) ≡ ¬p ∧ ¬q`

### Tautologia

Expressão que é sempre verdadeira.

`p ∨ ¬p`

### Contradição

Expressão que é sempre falsa.

`p ∧ ¬p`

### Contingência

Expressão que pode ser verdadeira ou falsa dependendo dos valores das proposições.

### Precedência lógica

`¬ → ∧ → ∨`

---

## Atividade prática

Considere:

- `p = usuário é administrador`
- `q = usuário é moderador`
- `r = usuário está bloqueado`

Expressão matemática:

`(p ∨ q) ∧ ¬r`

Valores:

- `p = V`
- `q = F`
- `r = F`

Resolução:

`(V ∨ F) ∧ ¬F`

`V ∧ V`

`V`

Em C++:

```cpp
bool admin = true;
bool moderador = false;
bool bloqueado = false;

if ((admin || moderador) && !bloqueado) {
    std::cout << "Pode acessar";
} else {
    std::cout << "Acesso negado";
}
```

**Resultado:** `Pode acessar`