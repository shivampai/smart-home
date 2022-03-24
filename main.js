function load() {
    random = Math.floor(Math.random() * 999);
    document.getElementById('randomno').innerHTML = random;
    firebase.database().ref('smarthome/'+random+'/active').set(false);
    firebase.database().ref('smarthome/'+random+'/active').on('value', (snapshot) => {
        const data = snapshot.val();
        console.log(data);
        active = data;
        if (active == true) {
            document.getElementById('layer').style.display = 'none';
        } else {
            document.getElementById('layer').style.display = 'block';
        }
    })
}