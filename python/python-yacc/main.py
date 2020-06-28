# In The Name Of God
# ========================================
# [] File Name : main.py
#
# [] Creation Date : 23-10-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
import ply.lex as lex
import ply.yacc as yacc

tokens = (
    'NAME', 'NUMBER',
)

literals = ['=', '+', '-', '*', '/', '(', ')', ';']

t_NAME = r'[a-zA-Z_][a-zA-Z0-9_]*'


def t_NUMBER(t):
    r'\d+'
    try:
        t.value = int(t.value)
    except ValueError:
        print("Integer value too large %d", t.value)
        t.value = 0
    return t


# Ignored characters
t_ignore = " \t"


def t_newline(t):
    r'\n+'
    t.lexer.lineno += t.value.count("\n")


def t_error(t):
    print("Illegal character '%s'" % t.value)
    t.lexer.skip(1)


# Build the lexer
lexer = lex.lex()

# Parsing rules

precedence = (
        ('left', '+', '-'),
        ('left', '*', '/'),
        ('right', 'UMINUS'),
)

# dictionary of names
names = {}

# temporary variables
inc = 0


def p_program(p):
    '''
    program : program statement
            | statement
    '''
    pass


def p_statement_assign(p):
    'statement : NAME "=" expression ";"'
    print('%s = MOV %s' % (p[1], p[3]))
    names[p[1]] = p[3]


def p_expression_binop(p):
    '''expression : expression '+' expression
                  | expression '-' expression
                  | expression '*' expression
                  | expression '/' expression'''
    global inc
    p[0] = 't%d' % inc
    inc = inc + 1
    if p[2] == '+':
        print('%s = ADD %s %s' % (p[0], p[1], p[3]))
    elif p[2] == '-':
        print('%s = MINUS %s %s' % (p[0], p[1], p[3]))
    elif p[2] == '*':
        print('%s = MULT %s %s' % (p[0], p[1], p[3]))
    elif p[2] == '/':
        print('%s = DIV %s %s' % (p[0], p[1], p[3]))


def p_expression_uminus(p):
    "expression : '-' expression %prec UMINUS"
    global inc
    p[0] = 't%d' % inc
    inc = inc + 1
    print('%s = MINUS 0 %s' % (p[0], p[2]))


def p_expression_group(p):
    "expression : '(' expression ')'"
    p[0] = p[2]


def p_expression_number(p):
    "expression : NUMBER"
    p[0] = p[1]


def p_expression_name(p):
    "expression : NAME"
    try:
        p[0] = names[p[1]]
    except LookupError:
        print("Undefined name '%s'" % p[1])
        p[0] = 0


# Error rule for syntax errors
def p_error(p):
    print("Syntax error in input: %s" % p)


# Test it out
data = '''
A = 1 + 3 * 4;
B = A + 1;
'''

# Give the ply some input
yacc.yacc()
yacc.parse(data)
