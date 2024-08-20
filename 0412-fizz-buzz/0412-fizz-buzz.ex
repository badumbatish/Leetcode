defmodule Solution do
  @spec fizz_buzz(n :: integer) :: [String.t]
  def fizz_buzz(n) do
    

    Enum.map(1..n, fn x ->
        case {rem(x ,3 )== 0 , rem(x,5) == 0} do
            {true, true} -> "FizzBuzz"
            {true, false} -> "Fizz"
            {false, true} -> "Buzz"
            {_, _} -> Integer.to_string(x)
        end
    end)
  end
end