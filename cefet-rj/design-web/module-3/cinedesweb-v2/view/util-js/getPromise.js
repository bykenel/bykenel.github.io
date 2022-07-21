export function getPromise (method, url, data = null) {
    const promise = new Promise(function(resolve, reject) {
        let xhr = new XMLHttpRequest();
        xhr.open(method,url); 
        xhr.setRequestHeader('Content-Type', 'application/json');
        xhr.send(JSON.stringify(data));

        xhr.onreadystatechange = function() {
            if(xhr.readyState === 4 ) {
                if( !(xhr.status === 200 || xhr.status === 304) ) {
                    reject(Error('Erro do cliente '+xhr.status+' - '+xhr.statusText));
                }

                if(xhr.status === 200 || xhr.status === 304) {
                    let response = JSON.parse(xhr.responseText);
                    resolve(response);
                }
            }           
        }
    })
    console.log(promise);
    return promise;
}