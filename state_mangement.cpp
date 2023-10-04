// vending machine state management low level design
// idlestate->moneystate->orderplaced->dispatched
// ->collect money()
// ->refund()
// cancel()
// search_order()

#include <bits/stdc++.h>

using namespace std;
class Product
{
public:
    int r;
    int c;
    int cost;
    string name;
    Product(int r, int c, int cost = 10, string name = "any_product")
    {
        this->r = r;
        this->c = c;
        this->cost = cost;
    }
};
class state
{
public:
    void start(class vending_machine *v1);
    void take_coins(class vending_machine *v1, int val);
    void place_order(class vending_machine *v1);
    void order_get(class vending_machine *v1, int r, int c);
    void dispatching(class vending_machine *v1);
    void cancel(vending_machine *v1);
};

class vending_machine
{
public:
    int tr;
    int tc;
    vector<vector<Product *>> inv;
    state curr;
    int money;
    Product *order;
    vending_machine(state current)
    {
        tr = 5;
        tc = 5;
        vector<vector<Product *>> inv1(tr, vector<Product *>(tc, NULL));
        this->inv = inv1;
        this->money = 0;
        this->order = NULL;
        this->curr = current;
    }
    void remove_product(int r, int c)
    {
        if (r >= 0 && r < tr && c >= 0 && c < tc && inv[r][c] != NULL)
        {
            inv[r][c] = NULL;
            cout << "product remove succccesfully" << endl;
        }
        else
        {
            cout << "row or column is invalid" << endl;
        }
        return;
    }
    void add_product(int r, int c, Product *p)
    {
        if (r >= 0 && r < tr && c >= 0 && c < tc && inv[r][c] != NULL)
        {
            inv[r][c] = p;
            cout << "product add succccesfully" << endl;
        }
        else
        {
            cout << "row or column is invalid" << endl;
        }
        return;
    }
    void change_state(state newstate)
    {
        this->curr = newstate;
        return;
    }
    void refund()
    {
        cout << "COLLECT YPUR REFUND" << this->money << endl;
        this->money = 0;
        this->reverse();
        this->order = NULL;
    }
    void reverse();
};

class dispatchstate : public state
{
public:
    void dispatching(vending_machine *v1)
    {
        if (v1->order != NULL)
        {
            v1->remove_product(v1->order->r, v1->order->c);
            v1->money = v1->money - v1->order->cost;
            v1->refund();
            v1->reverse();

            cout << "Please collect your order" << endl;
        }
    }
    void cancel(vending_machine *v1)
    {
        cout << "order can not be cancelled" << endl;
    }
};
class orderstate : public state
{
public:
    void order_get(vending_machine *v1, int r, int c)
    {
        if (r >= 0 && r < v1->tr && c >= 0 && c < v1->tc && v1->inv[r][c] != NULL && v1->inv[r][c]->cost <= v1->money)
        {
            cout << "order identified now dispatching" << endl;
            state dispatch = dispatchstate();
            v1->change_state(dispatch);
        }
    }
};
class moneystate : public state
{
public:
    void take_coins(vending_machine *v1, int val)
    {
        v1->money += val;
        return;
    }
    void place_order(vending_machine *v1)
    {
        state order = orderstate();
        v1->change_state(order);
        return;
    }
};
class idlestate : public state
{
public:
    void start(vending_machine *v1)
    {
        state money = moneystate();
        v1->change_state(money);
        return;
    }
};

void vending_machine::reverse()
{
    state nt = idlestate();
    this->change_state(nt);
    return;
}

void state::start(vending_machine *v1)
{
    throw exception();
}
void state::take_coins(vending_machine *v1, int val)
{
    throw exception();
}
void state::place_order(vending_machine *v1)
{
    throw exception();
}
void state::order_get(vending_machine *v1, int r, int c)
{
    throw exception();
}
void state::dispatching(vending_machine *v1)
{
    throw exception();
}
void state::cancel(vending_machine *v1)
{
    v1->refund();
}

int main()
{

    return 0;
}
