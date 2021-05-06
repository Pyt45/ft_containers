#ifndef TREE_CLASS_HPP
# define TREE_CLASS_HPP

# include <iostream>
# include <iomanip>

const int count = 5;

typedef struct 		s_node
{
    int     		key;
    struct s_node 	*left;
    struct s_node 	*right;
}					t_node;

class Btree {
	public:
		Btree();
		~Btree();
		void		insert(int key);
		void		destroy_tree();
		t_node		*search(int key);
		void		inorder_print();
		void		postorder_print();
		void		preorder_print();
		void		printBtree();
		void		printInAFantasticWay();
		void		printInPrettyWay();
    private:
        t_node		*root;
        void		insert(int key, t_node *leaf);
        void		destroy_tree(t_node *leaf);
        t_node		*search(int key, t_node *leaf);
	    void		inorder_print(t_node *leaf);
	    void		postorder_print(t_node *leaf);
	    void		preorder_print(t_node *leaf);
        void		printBtree(t_node *leaf, int space);
		void		printInAFantasticWay(t_node *leaf, std::string const & prefix);
		void		printInPrettyWay(t_node *leaf, int indent);
};

#endif