

def max_profit(coupons, products):
    pos_coupons, neg_coupons = [], []
    for coupon in coupons:
        if coupon > 0:
            pos_coupons.append(coupon)
        else:
            neg_coupons.append(coupon)
    pos_products, neg_products = [], []
    for product in products:
        if product > 0:
            pos_products.append(product)
        else:
            neg_products.append(product)
    pos_coupons.sort(reverse=True)
    neg_coupons.sort()
    pos_products.sort(reverse=True)
    neg_products.sort()
    money = 0
    for coupon, product in zip(pos_coupons, pos_products):
        money += coupon * product
    for coupon, product in zip(neg_coupons, neg_products):
        money += coupon * product
    return money


if __name__ == '__main__':
    _ = input()
    coupons = [int(i) for i in input().split()]
    _ = input()
    products = [int(i) for i in input().split()]
    print(max_profit(coupons, products))
