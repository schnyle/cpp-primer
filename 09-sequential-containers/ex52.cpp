// Use a stack to process parenthesized expressions. When you seen an open
// parenthesis, note that it was seen. When you see a close parenthesis after
// and open parenthesis, pop elements down to and including the open parenthesis
// off the stack. push a value onto the stack to indicate that parenthesized
// expression was replaced/