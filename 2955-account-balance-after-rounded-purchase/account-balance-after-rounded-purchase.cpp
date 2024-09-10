class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int total=100;
        if(purchaseAmount<5)
        {
            total-=0;
        }
        else if(purchaseAmount<15)
        {
            total-=10;
        }
        else if(purchaseAmount<25)
        {
            total-=20;
        }
        else if(purchaseAmount<35)
        {
            total-=30;
        }
        else if(purchaseAmount<45)
        {
            total-=40;
        }
        else if(purchaseAmount<55)
        {
            total-=50;
        }else if(purchaseAmount<65)
        {
            total-=60;
        }else if(purchaseAmount<75)
        {
            total-=70;
        }else if(purchaseAmount<85)
        {
            total-=80;
        }else if(purchaseAmount<95)
        {
            total-=90;
        }else if(purchaseAmount<=100)
        {
            total-=100;
        }
        return total;

    }
};