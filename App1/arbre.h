#ifndef ARBRE
#define ARBRE

#endif // ARBRE

#include <sstream>

template<typename T> class node
{
private:
    T value;
    int depth;
    node * left;
    node * right;
public:
    T getValue() const { return this->value;}
    node() : left(NULL), right(NULL), depth(0) {}
    node(T value) : value(value), depth(0),left(NULL), right(NULL){}
    node(node<T> & t1) : left(NULL), right(NULL), depth(0), value(t1.value) {}
    node(const node<T> & t, int depth) : value(t.value), depth(depth),left(NULL), right(NULL){}
    ~node()
    {
        delete(left);
        delete(right);
    }

    void add(node<T> & t1)
    {
        if(this->value > t1.value)
        {
            if(!this->left)
            {
                this->left = new node(t1,depth+1);
            }
            else
            {
                this->left->add(t1);
            }
        }
        else
        {
            if(!this->right)
            {
                this->right = new node(t1,depth+1);
            }
            else
            {
                this->right->add(t1);
            }
        }
    }

    node * searchNode(const T value)
    {
        node * ret = NULL;

        if(this->value == value)
        {
            ret = this;
        }
        else  if(this->value < value)
        {
            ret =this->right ? this->right->searchNode(value) : NULL;
        }
        else
        {
            ret =this->left ? this->left->searchNode(value) : NULL;
        }
        return ret;
    }

    node * searchFatherNode(const T & value)
    {
        node * ret = NULL;
        if(this->right && this->right->value == value)
        {
            ret = this;
        }
        else if(this->left && this->left->value == value)
        {
            ret = this;
        }
        else if(this->right && this->value < value)
        {
            ret =this->right->searchFatherNode(value);
        }
        else if(this->left)
        {
            ret =this->left->searchFatherNode(value);
        }
        return ret;
    }

    void add(node<T> * destination,node<T> * source)
    {
        if(source == NULL)
        {
            return;
             }

        if(destination->value < source->value)
        {
            if(destination->right == NULL)
            {
               destination->right = source;
            }
            else
            {
            add(destination->right,source);
            }

        }
        else
        {
            if(destination->left == NULL)
            {
               destination->left = source;
            }
            else
            {
            add(destination->left,source);
            }
        }
    }

    void remove(const T & value)
    {
        node * n = this->searchFatherNode(value);
        if(n->left && n->left->value == value)
        {
            node * tmp = n->left->right;
            node * tmp2 = n->left;
            n->left->right = NULL;
            n->left = tmp2->left;
            tmp2->left = NULL;
            tmp2->right = NULL;
            delete(tmp2);
            add(n,tmp);
        }
        else if(n->right && n->right->value == value)
        {
            node * tmp = n->right->right;
            node * tmp2 = n->right;
            n->right->right = NULL;
            n->right = tmp2->left;
            tmp2->left = NULL;
            tmp2->right = NULL;
            delete(tmp2);
            add(n,tmp);

        }
    }

    void display(std::stringstream & s)
    {
        if(this->left)
        {
            this->left->display(s);
            s << "_";
        }

        s<< this->value;

        if(this->right)
        {
            s << "_";
            this->right->display(s);
        }
    }

};

void testNode(std::stringstream & output)
{
    node<int> n1(1);
    node<int> n2(2);
    node<int> n3(3);
    node<int> n4(4);
    node<int> n5(5);
    node<int> n6(6);
    node<int> n7(7);
    node<int> n8(8);
    node<int> n9(9);

    n5.add(n4);
    n5.add(n6);
    n5.add(n3);
    n5.add(n7);
    n5.add(n2);
    n5.add(n9);
    n5.add(n8);
    n5.add(n1);

    output << "affichage arbre binaire initial :" << std::endl;
    n5.display(output);
    output << std::endl << "recherche du 6" << std::endl;
    int i = 6;
    node<int> * p = n5.searchNode(i);
    output << ((p && p->getValue() == i) ? "searchNode :OK" : "searchNode :KO")  << std::endl;
    output << "suppression du 3" << std::endl;
    n5.remove(3);
    n5.display(output);
	output << std::endl;
    output << "suppression du 7" << std::endl;
    n5.remove(7);
    n5.display(output);
	output << std::endl;

	node<int> n3bis(3);
	output << "rajout du 3" << std::endl;
	n5.add(n3bis);
	n5.display(output);
	output << std::endl;

}


