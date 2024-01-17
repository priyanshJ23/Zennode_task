#include<bits/stdc++.h>
using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
    bool isGiftWrapped;
};

struct Discount {
    string name;
    double amount;
};


int main() {

    Product categories[] = {
        {"Product A", 20.0, 0, false},
        {"Product B", 40.0, 0, false},
        {"Product C", 50.0, 0, false}
    };
    for (int i = 0; i < 3; i++) {
        cout << "Enter quantity for " <<categories[i].name << " : ";
        cin >>categories[i].quantity;
        cout << "Gift wrapped needed ? (if no press 0 , else press 1): ";
        cin >>categories[i].isGiftWrapped;
        cout << endl;
    }


    const double gift_wrap_fee = 1.0;
    const double shipping_fee_per_package = 5.0;
    const int units_per_package = 10;

    double subtotal = 0.0;
    int total_quantity;
    for (const Product& product :categories) {
        subtotal += product.price * product.quantity;
        total_quantity = total_quantity + product.quantity;
    }

    Discount appliedDiscount[] = {
        {"No Discount", 0.0},
        {"Product A", 20.0*categories[0].quantity},
        {"Product B", 40.0*categories[1].quantity},
        {"Product C", 50.0*categories[2].quantity}
    };
    
    if (subtotal > 200) {
        int p = subtotal;
        double curr_amount_discount = subtotal - 10;
        if(curr_amount_discount < ( subtotal - appliedDiscount[0].amount)){
        appliedDiscount[0].amount = 10;
        appliedDiscount[0].name = "flat_10_discount";
        }
    } 

    if((categories[0].quantity <= 10 && categories[1].quantity<=10 && categories[2].quantity > 10) || (categories[0].quantity <= 10 && categories[1].quantity > 10 && categories[2].quantity <= 10) || (categories[0].quantity > 10 && categories[1].quantity <=10 && categories[2].quantity <= 10))
    {
      double k = subtotal; 
      for (int i = 0; i < 3; ++i) {
      if (categories[i].quantity > 10) {
            double productDiscount = categories[i].price * categories[i].quantity * 0.05;
            k  -= productDiscount;
      }
      double curr_amount_discount = k;
      if(curr_amount_discount < (subtotal - appliedDiscount[0].amount))
      {
          appliedDiscount[0].amount = categories[i].price * categories[i].quantity * 0.05;
          appliedDiscount[0].name = "bulk_5_discount";
          appliedDiscount[i+1].amount = categories[i].price * categories[i].quantity - (categories[i].price * categories[i].quantity * 0.05);
      }   
    }
    }

    if(total_quantity > 20)
    {
        int pro = subtotal;
        double curr_discount = subtotal * 0.10;
        double curr_amount_discount = subtotal - curr_discount;
        if(curr_amount_discount < (subtotal - appliedDiscount[0].amount))
        {
             appliedDiscount[0].amount = curr_discount;
             appliedDiscount[0].name =  "bulk_10_discount";
        }
    } 

    if((categories[0].quantity > 15 && total_quantity > 30) || (categories[1].quantity > 15 && total_quantity > 30) || (categories[2].quantity > 15 && total_quantity > 30)){
     for(int i = 0; i < 3; ++i) {
        int j = subtotal;
        if (categories[i].quantity > 15 && categories[0].quantity + categories[1].quantity + categories[2].quantity > 30) {
            double discountedQuantity = categories[i].quantity - 15;
            j -= (categories[i].price * discountedQuantity * (1 - 0.50));
            double curr_amount_discount = subtotal - (categories[i].price * discountedQuantity * (1 - 0.50));
            if(curr_amount_discount < (subtotal - appliedDiscount[0].amount))
            {
                appliedDiscount[0].amount = (categories[i].price * discountedQuantity * (1 - 0.50));
                appliedDiscount[0].name = "tiered_50_discount";
                appliedDiscount[i+1].amount =  categories[i].price * 15 + (categories[i].price * discountedQuantity * (1 - 0.50));
            }
         
        } 
    }
    }
     
    /*Calculating gift wrap fee */
    double giftWrapFee = 0.0;
    for (const Product& product :categories) {
        if (product.isGiftWrapped) {
            giftWrapFee += product.quantity * 1;
        }
    }

    /* Calculating shipping fee */
    double shippingFee = ceil(total_quantity/10.0) * 5;

    // Calculating total 
    double total = subtotal - appliedDiscount[0].amount + shippingFee + giftWrapFee;

    // Output details
    cout << fixed << setprecision(2);
    cout<<"ProductName " << "Quantity " << "Amount_After_discount"<<endl;
    cout<<appliedDiscount[1].name << "    "<< categories[0].quantity << "   $" << appliedDiscount[1].amount<<endl;
    cout<<appliedDiscount[2].name << "    "<< categories[1].quantity << "   $" << appliedDiscount[2].amount<<endl;
    cout<<appliedDiscount[3].name << "    "<< categories[2].quantity << "   $" << appliedDiscount[3].amount<<endl;

    cout << "Subtotal_Without_discount: $" << subtotal << endl;
    cout << "Discount Applied: " << appliedDiscount[0].name << " - $" << appliedDiscount[0].amount << endl;
    cout<<"Subtotal_After_discount : $"<<subtotal - appliedDiscount[0].amount <<endl;
    cout << "Gift Wrap Fee: $" << giftWrapFee << endl;
    cout << "Shipping Fee: $" << shippingFee << endl;
    cout << "Total: $" << total << endl;

    return 0;
}