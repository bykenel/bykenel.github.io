numberPrime (4)

function numberPrime(max) {
    for (let i = 2; i <= max; i++){
        let prime = true;
        for(let div = 2; div < i; div++){
            if(i % div === 0){
                prime = false;
                break;
            }
        }
        if (prime) {
            let primeList = new Array();
            primeList.push(i);
            console.log(primeList)
        }
    }
}