/*
I've invited some kids for my son's birthday, during which I will give to each kid some amount of candies.

Every kid hates receiving less amount of candies than any other kids, and I don't want to have any candies left - giving it to my kid would be bad for his teeth.

However, not every kid invited will come to my birthday party.

What is the minimum amount of candies I have to buy, so that no matter how many kids come to the party in the end, I can still ensure that each kid can receive the same amount of candies, while leaving no candies left?

It's ensured that at least one kid will participate in the party.*/

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return (a / gcd(a, b)) * b;
}

unsigned long long candies_to_buy(unsigned char invited) {
    unsigned long long min_cnt = 1;
    for (unsigned long long i = 2; i <= invited; ++i) {
        min_cnt = lcm(min_cnt, i);
    }
    return min_cnt;
}