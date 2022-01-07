from typing import NamedTuple, Iterable, Union
import re

class Token(NamedTuple):
    type: str
    value: Union[str, float, int]
    column: int

def tokenize(expression: str) -> Iterable[Token]:
    token_specification = [
        ('NUMBER',   r'\d+(\.\d*)?'),
        ('OPEN_PARN',   r'\('),
        ('CLOSE_PARN',   r'\)'),
        ('SUM',   r'\+'),
        ('MINUS',   r'\-'),
        ('MUL',   r'\*'),
        ('DIV',   r'\/'),
        ('SKIP',     r'[ \t]+'),
        ('MISMATCH', r'.'),
    ]
    tok_regex = '|'.join(f'(?P<{name}>{regex})' for (name, regex) in token_specification)
    for mo in re.finditer(tok_regex, expression):
        kind = mo.lastgroup
        value = mo.group()
        column = mo.start()
        if kind == 'NUMBER':
            value = float(value) if '.' in value else int(value)
        elif kind == 'SKIP':
            continue
        elif kind == 'MISMATCH' or kind is None:
            raise RuntimeError(f'{value!r} unexpected on {column}')
        yield Token(kind, value, column)

class Calculator:
    op = {
        '+': lambda x, y: x + y,
        '-': lambda x, y: x - y,
        '*': lambda x, y: x * y,
        '/': lambda x, y: x / y,
    }

    def to_postfix(self, s: str) -> str:
        stack = []
        ret = ''

        for token in tokenize(s):
            if token.type in ('MUL', 'DIV'):
                while len(stack) > 0 and stack[-1] in ('*', '/'):
                    ret += str(stack.pop()) + ' '
                stack.append(token.value)
            elif token.type in ('SUM', 'MINUS'):
                while len(stack) > 0 and stack[-1] != '(':
                    ret += str(stack.pop()) + ' '
                stack.append(token.value)
            elif token.type == 'OPEN_PARN':
                stack.append(token.value)
            elif token.type == 'CLOSE_PARN':
                while len(stack) > 0 and stack[-1] != '(':
                    ret += str(stack.pop()) + ' '
                stack.pop()
            else:
                ret += str(token.value) + ' '
        while len(stack) > 0:
            ret += str(stack.pop()) + ' '
        return ret

    def eval_postfix(self, s: str) -> float:
        st = []
        tokens = s.split()
        for tok in tokens:
            if tok not in self.op:
                st.append(float(tok))
            else:
                n1 = float(st.pop())
                n2 = float(st.pop())
                st.append(self.op[tok](n2, n1))
        return st.pop()

    def evaluate(self, s: str):
        s = self.to_postfix(s)
        return self.eval_postfix(s)


calc = Calculator()

print(calc.evaluate('1378 + 1373'))
print(calc.evaluate('78 - 73 * 0'))
print(calc.evaluate('78 - 73'))
print(calc.evaluate('(78 - 73) * 9'))

