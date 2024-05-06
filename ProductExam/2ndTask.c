float avrg_by_price(struct Product *products, int n, float price) {
    int count = 0;
    float sum = 0;

    for (int i = 0; i < n; i++) {
        if (products[i].price < price) {
            sum += products[i].price;
            count++;
        }
    }

    if (count == 0) {
        return 0;
    }

    return sum / count;
}
