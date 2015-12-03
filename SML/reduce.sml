datatype 'a tree = LEAF of 'a |
                   NODE of ('a tree * 'a tree);
fun apply(f, NODE(x, y)) = f(apply(f, x), apply(f, y)) |
    apply(f, LEAF(x)) = x;
fun reduce(f) = fn (x) => apply(f, x);
fun f(x, y) = x + y;
reduce f(NODE(NODE(LEAF 1, LEAF 2), LEAF 3));
