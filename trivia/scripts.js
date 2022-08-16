
const answer1 = 'Bruce';
const answer2 = 'Robin';

document.addEventListener('DOMContentLoaded', (event) => {

    // Change button color depending on answer
    const btn_group = document.getElementById('btn-group');
    btn_group.addEventListener('click', (event) => {
        const is_btn = event.target.nodeName === 'BUTTON';
        if(!is_btn) return;
        btn_id = event.target.id;
        if(btn_id === answer1) {
            btn = document.getElementById(btn_id);
            btn.style.backgroundColor = '#66ff66';
            document.querySelector("#feedback_btn").innerHTML = "Correct!";
        }
        else if(btn_id !== answer1) {
            btn = document.getElementById(btn_id);
            btn.style.backgroundColor = '#ff6666';
            document.querySelector("#feedback_btn").innerHTML = "Incorrect!";
        }
    });

    document.querySelector('form').addEventListener('submit', (event) => {
        let response = document.querySelector('#name').value;
        const response_lower = response.toLowerCase();
        const answer2_lower = answer2.toLowerCase();
        const text_field = document.getElementById('name');

        if(answer2_lower === response_lower) {
            document.querySelector('#feedback_txt').innerHTML = "Correct!";
            text_field.style.backgroundColor = '#66ff66';
        } else {
            document.querySelector('#feedback_txt').innerHTML = "Incorrect!";
            text_field.style.backgroundColor = '#ff6666';
        }

        event.preventDefault();
    });

});
