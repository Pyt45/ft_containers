#pragma once

template <class _NodePtr>
void
__tree_remove(_NodePtr __root, _NodePtr __z)
{
    // __z will be removed from the tree.  Client still needs to destruct/deallocate it
    // __y is either __z, or if __z has two children, __tree_next(__z).
    // __y will have at most one child.
    // __y will be the initial hole in the tree (make the hole at a leaf)
    _NodePtr __y = (__z->__left_ == nullptr || __z->__right_ == nullptr) ?
                    __z : __tree_next(__z);
    // __x is __y's possibly null single child
    _NodePtr __x = __y->__left_ != nullptr ? __y->__left_ : __y->__right_;
    // __w is __x's possibly null uncle (will become __x's sibling)
    _NodePtr __w = nullptr;
    // link __x to __y's parent, and find __w
    if (__x != nullptr)
        __x->__parent_ = __y->__parent_;
    if (__tree_is_left_child(__y))
    {
        __y->__parent_->__left_ = __x;
        if (__y != __root)
            __w = __y->__parent_unsafe()->__right_;
        else
            __root = __x;  // __w == nullptr
    }
    else
    {
        __y->__parent_unsafe()->__right_ = __x;
        // __y can't be root if it is a right child
        __w = __y->__parent_->__left_;
    }
    bool __removed_black = __y->__is_black_;
    // If we didn't remove __z, do so now by splicing in __y for __z,
    //    but copy __z's color.  This does not impact __x or __w.
    if (__y != __z)
    {
        // __z->__left_ != nulptr but __z->__right_ might == __x == nullptr
        __y->__parent_ = __z->__parent_;
        if (__tree_is_left_child(__z))
            __y->__parent_->__left_ = __y;
        else
            __y->__parent_unsafe()->__right_ = __y;
        __y->__left_ = __z->__left_;
        __y->__left_->__set_parent(__y);
        __y->__right_ = __z->__right_;
        if (__y->__right_ != nullptr)
            __y->__right_->__set_parent(__y);
        __y->__is_black_ = __z->__is_black_;
        if (__root == __z)
            __root = __y;
    }
    // There is no need to rebalance if we removed a red, or if we removed
    //     the last node.
    if (__removed_black && __root != nullptr)
    {
        // Rebalance:
        // __x has an implicit black color (transferred from the removed __y)
        //    associated with it, no matter what its color is.
        // If __x is __root (in which case it can't be null), it is supposed
        //    to be black anyway, and if it is doubly black, then the double
        //    can just be ignored.
        // If __x is red (in which case it can't be null), then it can absorb
        //    the implicit black just by setting its color to black.
        // Since __y was black and only had one child (which __x points to), __x
        //   is either red with no children, else null, otherwise __y would have
        //   different black heights under left and right pointers.
        // if (__x == __root || __x != nullptr && !__x->__is_black_)
        if (__x != nullptr)
            __x->__is_black_ = true;
        else
        {
            //  Else __x isn't root, and is "doubly black", even though it may
            //     be null.  __w can not be null here, else the parent would
            //     see a black height >= 2 on the __x side and a black height
            //     of 1 on the __w side (__w must be a non-null black or a red
            //     with a non-null black child).
            while (true)
            {
                if (!__tree_is_left_child(__w))  // if x is left child
                {
                    if (!__w->__is_black_)
                    {
                        __w->__is_black_ = true;
                        __w->__parent_unsafe()->__is_black_ = false;
                        __tree_left_rotate(__w->__parent_unsafe());
                        // __x is still valid
                        // reset __root only if necessary
                        if (__root == __w->__left_)
                            __root = __w;
                        // reset sibling, and it still can't be null
                        __w = __w->__left_->__right_;
                    }
                    // __w->__is_black_ is now true, __w may have null children
                    if ((__w->__left_  == nullptr || __w->__left_->__is_black_) &&
                        (__w->__right_ == nullptr || __w->__right_->__is_black_))
                    {
                        __w->__is_black_ = false;
                        __x = __w->__parent_unsafe();
                        // __x can no longer be null
                        if (__x == __root || !__x->__is_black_)
                        {
                            __x->__is_black_ = true;
                            break;
                        }
                        // reset sibling, and it still can't be null
                        __w = __tree_is_left_child(__x) ?
                                    __x->__parent_unsafe()->__right_ :
                                    __x->__parent_->__left_;
                        // continue;
                    }
                    else  // __w has a red child
                    {
                        if (__w->__right_ == nullptr || __w->__right_->__is_black_)
                        {
                            // __w left child is non-null and red
                            __w->__left_->__is_black_ = true;
                            __w->__is_black_ = false;
                            __tree_right_rotate(__w);
                            // __w is known not to be root, so root hasn't changed
                            // reset sibling, and it still can't be null
                            __w = __w->__parent_unsafe();
                        }
                        // __w has a right red child, left child may be null
                        __w->__is_black_ = __w->__parent_unsafe()->__is_black_;
                        __w->__parent_unsafe()->__is_black_ = true;
                        __w->__right_->__is_black_ = true;
                        __tree_left_rotate(__w->__parent_unsafe());
                        break;
                    }
                }
                else // x is a right child
                {
                    if (!__w->__is_black_)
                    {
                        __w->__is_black_ = true;
                        __w->__parent_unsafe()->__is_black_ = false;
                        __tree_right_rotate(__w->__parent_unsafe());
                        // __x is still valid
                        // reset __root only if necessary
                        if (__root == __w->__right_)
                            __root = __w;
                        // reset sibling, and it still can't be null
                        __w = __w->__right_->__left_;
                    }
                    // __w->__is_black_ is now true, __w may have null children
                    if ((__w->__left_  == nullptr || __w->__left_->__is_black_) &&
                        (__w->__right_ == nullptr || __w->__right_->__is_black_))
                    {
                        __w->__is_black_ = false;
                        __x = __w->__parent_unsafe();
                        // __x can no longer be null
                        if (!__x->__is_black_ || __x == __root)
                        {
                            __x->__is_black_ = true;
                            break;
                        }
                        // reset sibling, and it still can't be null
                        __w = __tree_is_left_child(__x) ?
                                    __x->__parent_unsafe()->__right_ :
                                    __x->__parent_->__left_;
                        // continue;
                    }
                    else  // __w has a red child
                    {
                        if (__w->__left_ == nullptr || __w->__left_->__is_black_)
                        {
                            // __w right child is non-null and red
                            __w->__right_->__is_black_ = true;
                            __w->__is_black_ = false;
                            __tree_left_rotate(__w);
                            // __w is known not to be root, so root hasn't changed
                            // reset sibling, and it still can't be null
                            __w = __w->__parent_unsafe();
                        }
                        // __w has a left red child, right child may be null
                        __w->__is_black_ = __w->__parent_unsafe()->__is_black_;
                        __w->__parent_unsafe()->__is_black_ = true;
                        __w->__left_->__is_black_ = true;
                        __tree_right_rotate(__w->__parent_unsafe());
                        break;
                    }
                }
            }
        }
    }
}

    ns::vector<int> vector_int;
    vector_int.assign(3, 2);
    std::cout << "insert(p, v)\n";
    ns::vector<int>::iterator it = vector_int.insert(vector_int.begin(), 10);
    std::cout << "vector_int size: " << vector_int.size() << std::endl;
    std::cout << "vector_int capactiy: " << vector_int.capacity() << std::endl;
    std::cout << "insert(p, v)\n";
    it = vector_int.insert(vector_int.end(), 100);
    std::cout << *it << std::endl;
    for (ns::vector<int>::iterator b = vector_int.begin(); b != vector_int.end(); b++)
        std::cout << *b<< std::endl;
    std::cout << "insert(p, n, v)\n";
    vector_int.insert(it, 2, 6); // n = 70
    std::cout << "vector_int size: " << vector_int.size() << std::endl;
    std::cout << "vector_int capactiy: " << vector_int.capacity() << std::endl;
    for (ns::vector<int>::iterator b = vector_int.begin(); b != vector_int.end(); b++)
        std::cout << *b<< std::endl;
    ns::vector<int> vector_range;
    vector_range.assign(3, 4);
    ns::vector<int>::iterator itv = vector_range.begin();
    // // itv++;
    // // itv++;
    // // itv++;
    std::cout << "insert(p, f, l)\n";
    vector_range.insert(itv, vector_int.begin(), vector_int.end());
    for (int i = 0; i < (int)vector_range.size(); i++)
        std::cout << vector_range[i] << std::endl;