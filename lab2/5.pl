# Преобразовать слово, расставив между его буквами знаки "_". Вывести итоговое слово на экран.
my $someWord = "helicopter";
print("Input data:\n$someWord\nOutput:\n");

print(join ("_", split('', $someWord))); # h_e_l_i_c_o_p_t_e_r
