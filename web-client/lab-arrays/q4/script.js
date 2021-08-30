value(5705)

function value(money) {
    let c100 = 0;
    let c50 = 0;
    let c20 = 0;
    let c10 = 0;
    let c5 = 0;
    let c2 = 0;

    if(money != 0) {
        for(;money >= 100;) {
            c100++;
            money -= 100;
        }
        
        for(;money >= 50;) {
            c50++;
            money -= 50;
        }
        
        for(;money >= 20;) {
            c20++;
            money -= 20;
        }
        
        for(;money >= 10;) {
            c10++;
            money -= 10;
        }
        
        for(;money >= 5;) {
            c5++;
            money -= 5;
        }
        
        for(;money >= 2;) {
            c2++;
            money -= 2;
        }    
    }
    console.log("100: " + c100);
    console.log("50: " + c50);
    console.log("20: " + c20);
    console.log("10: " + c10);
    console.log("5: " + c5);
    console.log("2: " + c2);
}