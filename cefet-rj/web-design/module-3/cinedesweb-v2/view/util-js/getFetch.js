export function getFetch (method, url, data = null) {
    let configMethod = null;
    if(method != "GET") {
        configMethod = {
            method : method,
            body : JSON.stringify(data),
            headers : {
                "Content-Type" : "application/json; charset=UTF-8"
            }
        }
    }
    const myFetch = fetch(url, configMethod)
    .then(response => verifyForError(response))
    .then(response => response.json())
    return myFetch;

    function verifyForError(response) {
        console.log(response);
        if(!response.ok)
            throw new Error(response.status + " - " + response.statusText);
        return response;
    }
}