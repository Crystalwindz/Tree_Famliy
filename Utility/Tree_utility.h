#ifndef _TREE_UTILITY_H_
#define _TREE_UTILITY_H_

#include<iostream>
#include<utility>

namespace treefamily {

	template <typename TREE, typename DATA>
	TREE& find_node(TREE& root, DATA& data) {
		if (root == nullptr)
			return root;
		
		if (root->data_ > data)
			return find_node(root->left_, data);
		else if (root->data_ < data)
			return find_node(root->right_, data);
		else
			return root;
	}
	
	template <typename TREE, typename DATA>
	std::pair<TREE&, TREE&> find_node_parent(TREE& root, DATA& data) {
		if (root == nullptr)
			return std::make_pair(root, root);

		if (root->data_ > data) {
			if (root->left_ == nullptr)
				return std::make_pair(root->left_, root);
			else
				return find_node_parent(root->left_, data);
		}
		else if (root->data_ < data) {
			if (root->right_ == nullptr)
				return std::make_pair(root->right_, root);
			else
				return find_node_parent(root->right_, data);
		}
		else
			return std::make_pair(root, root->parent_);
	}
	
	template <typename TREE>
	TREE& find_min(TREE& root) {
		if (root == nullptr)
			return root;
		
		if (root->left_ == nullptr)
			return root;
		else
			return find_min(root->left_);
	}

	template <typename TREE>
	TREE& find_max(TREE& root) {
		if (root == nullptr)
			return root;

		if (root->right_ == nullptr)
			return root;
		else
			return find_max(root->right_);
	}

	template <typename TREE>
	void clear_tree(TREE root) {
		if (root == nullptr)
			return;

		clear_tree(root->left_);
		clear_tree(root->right_);
		delete root;
	}

	template <typename TREE>
	void preorder_traversal(TREE root) {
		if (root == nullptr)
			return;

		preorder_traversal(root->left_);
		std::cout << root->data_ << std::endl;
		preorder_traversal(root->right_);
	}

	template <typename TREE>
	void postorder_traversal(TREE root) {
		if (root == nullptr)
			return;

		postorder_traversal(root->right_);
		std::cout << root->data_ << std::endl;
		postorder_traversal(root->left_);
	}

	template <typename TREE>
	inline TREE& grandparent(TREE& root) {
		return root->parent_->parent_;
	}

	template <typename TREE>
	inline TREE& parent(TREE& root) {
		return root->parent_;
	}

	template <typename TREE>
	inline TREE& uncle(TREE& root) {
		if (grandparent(root)->left_ == root)
			return grandparent(root)->right_;
		else
			return grandparent(root)->left_;
	}

	template <typename TREE>
	void right_rotate(TREE root) {
		TREE par     =  parent(root);
		par->left_    =  root->right_;
		if (root->right_ != nullptr)
			root->right_->parent_ = par_;
		root->right_  =  par;
		root->parent_ =  par->parent_;
		par->parent_  =  root;
		if (root->parent_ == nullptr)
			return;
		else if (root->parent_->left_ == par)
			root->parent_->left_ = root;
		else if (root->parent_->right_ == par)
			root->parent_->right_ = root;
	}

	template <typename TREE>
	void left_rotate(TREE root) {
		TREE par      =  parent(root);
		par->right_   =  root->left_;
		if (root->left_ != nullptr)
			root->left_->parent_ = par_;
		root->left_   =  par;
		root->parent_ =  par->parent_;
		par->parent_  =  root;
		if (root->parent_ == nullptr)
			return;
		else if (root->parent_->left_ == par)
			root->parent_->left_ = root;
		else if (root->parent_->right_ == par)
			root->parent_->right_ = root;
	}

	template <typename TREE>
	void left_right_rotate(TREE root) {
		left_rotate(root);
		right_rotate(root);
	}

	template <typename TREE>
	void right_left_rotate(TREE root) {
		right_rotate(root);
		left_rotate(root);
	}

}

#endif // !_TREE_UTILITY_H_
