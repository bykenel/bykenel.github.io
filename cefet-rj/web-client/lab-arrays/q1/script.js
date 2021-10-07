let numbers = [2,2,2];

//sum()
let sum = 0;
for (let i = 0; i < numbers.length; i++) {
    sum += numbers[i];
}
console.log("sum: "+ sum);

//sumOdds()
let sumOdds = 0;
for (let i = 0; i < numbers.length; i++) {
    if(numbers[i] % 2 != 0)
        sumOdds += numbers[i];
}
console.log("sumOdds: "+ sumOdds);

//product()
let product = 1;
for (let i = 0; i < numbers.length; i++) {
    product *= numbers[i];
}
console.log("product: "+ product);