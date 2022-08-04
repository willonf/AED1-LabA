// fn nome_da_funcao (parametro: tipo, ...) -> tipoDeRetorno {
//     escopo da funcao
//     retorno ímplicito da função: última linha
//     retorno explícito da função: return
// }

fn main(){
    let array: [i8; 2];
    const MATRIX1: [[i8; 3]; 2] = [[1,2,3], [4,5,6]];
    const MATRIX2: [[i8; 2]; 3] = [[1,2], [3,4], [5,6]];
    const N: usize = MATRIX1[0].len();
    const ROWS: usize = MATRIX1.len();
    const COLUMNS: usize = MATRIX2[0].len();
    let mut result: [[i8; COLUMNS]; ROWS] = [[0,0], [0,0]];

    for i in 0..ROWS {
        for j in 0..COLUMNS {
            for k in 0..N {
                result[i][j] += MATRIX1[i][k]*MATRIX2[k][j];
            }
        }
    }

    for i in 0..2 {
        for j in 0..2 {
            print!("{} ", result[i][j]);
        }
        println!();
    }

}

// fn hello_world(){
//     println!("Hello, World!");
// }

// fn odd_or_even(number: i16) -> bool {
//     if number % 2 == 0 {
//         return true;
//     }
//     return false
// }

// fn convert_celsius_to_fahr(temp: f32) -> f32 {
//     temp*1.8 + 32.0
// }

// fn loop_function() {
//     let mut number = 1;
//     println!("Even numbers between 1 and 10: ");
//     loop {
//         if odd_or_even(number){
//             println!("{}", number);
//         }
//         number += 1;
//         if number > 10 {
//             break;
//         }
//     }
//     println!();
// }


