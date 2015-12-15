datatype tree = leaf of int | node of tree * tree;
fun inTree(x, leaf(y)) = x = y
  | inTree(x, node(y, z)) = inTree(x, y) orelse inTree(x, z);
