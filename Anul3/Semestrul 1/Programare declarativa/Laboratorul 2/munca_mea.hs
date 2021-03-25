import Data.List
import Data.Char
double :: Integer -> Integer
double x = x + x

sumPatrate :: Integer -> Integer -> Integer
sumPatrate x y = x * x + y * y

fact :: Integer -> Integer
fact 1 = 1
fact n = n * fact(n-1)

dub::Integer -> Integer -> String
dub x y
  | x > 2 * y = "True"
  | otherwise = "False"

semipare:: [Integer] -> [Integer]
semipare [] = []
semipare (h:t)
  | even h = h `div` 2 : t1
  | otherwise = t1
  where t1 = semipare t

semipare2:: [Integer] -> [Integer]
semipare2 l = [x `div`2 | x <- l, even x ]

inInterval:: Integer -> Integer -> [Integer] -> [Integer]
inInterval p u l = [x | x <- l, x >= p, x <= u]

inIntervalRec:: Integer -> Integer -> [Integer] -> [Integer]
inIntervalRec p u [] = []
inIntervalRec p u (h:l)
  | h >= p && h <=u = h : t
  |otherwise = t
  where t = inIntervalRec p u l

pozitiveRec:: [Integer] -> Integer
pozitiveRec [] = 0
pozitiveRec (h:l)
  | h >=0 = 1 + pozitiveRec l
  | otherwise = pozitiveRec l

pozitiveRecListe :: [Integer] -> Int
pozitiveRecListe l = length[ x | x <- l, x >= 0]


pozitiiImpareAux:: Integer -> [Integer] -> [Integer]
pozitiiImpareAux _ [] = []
pozitiiImpareAux p (h:l)
  | even(h) = pozitiiImpareAux(p + 1) l
  | otherwise = p: pozitiiImpareAux(p + 1) l

pozitiiImpareRec :: [Integer] -> [Integer]
pozitiiImpareRec l = pozitiiImpareAux 0 l

pozitiiImpareD :: [Integer] -> [Integer]
pozitiiImpareD l = [snd(x) | x <-zip l [0..], odd(fst(x))]

sumString:: String -> Int
sumString [] = 1
sumString (h:t)
  | isDigit(h) = digitToInt(h) * sumString(t)
  | otherwise = sumString(t)

sumStringD:: String -> Int
sumStringD l = product[digitToInt(x) | x <-l, isDigit(x)]
{-}
discountRec :: [Float] -> [Float]
discountRec [] = []
discountRec (h:t)
  | nr < 200 = nr : discountRec(t)
  | otherwise = discountRec(t)
    where nr = 0.75 * h
-}
discountComp :: [Float] -> [Float]
discountComp l = [0.75 * x | x <- l, 0.75 * x < 200]

listaFactori:: Int -> Int -> [Int]
listaFactori n 0 = []
listaFactori n m
  | n `mod` m == 0 = m :t
  | otherwise = t
  where t = listaFactori n (m-1)

factori :: Int -> [Int]
factori n = listaFactori n n

prim :: Int -> Bool
prim n = length(factori n) == 2

numerePrime :: Int -> [Int]
numerePrime 1 = []
numerePrime n
  | prim n = n:t5
  | otherwise = t5
  where t5 = numerePrime(n-1)

firstEl :: [(a, b)] -> [a]
firstEl ((a, b):xs) = map fst((a, b):xs)


sumlist::[[Int]] -> [Int]
sumlist l = map (\x -> sum(x)) l

prel2::[Int] -> [Int]
prel2 l = map (\x -> if even(x) then x `div` 2 else x * 2 ) l

prelSir::Char -> [String] -> [String]
prelSir c l = filter (elem c) l

patImpare::[Int] -> [Int]
patImpare l = map (\x -> x*x) (filter (odd) l)

patImparePoz::[Int] -> [Int]
patImparePoz x = map (\(x,y)->y^2) (filter (odd.fst) (zip [0..] x))

ordonataNat::[Int] -> Bool
ordonataNat [ ] = True
ordonataNat [ x ] = True
ordonataNat ( x : xs ) = and [a < b | (a,b) <- zip (x:xs) xs]

prod::[Int] -> Int
prod [] = 1
prod (h:l) = h * prod(l)

prod1::[Int] -> Int
prod1 l = foldr (*) 1 l

andRec :: [Bool] -> Bool
andRec [] = True
andRec (h:l)
  | h = True && andRec(l)
  | otherwise = False

andFoldr::[Bool] -> Bool
andFoldr l = foldr (&&) True l

concatRec :: [[a]] -> [a]
concatRec [] = []
concatRec (h:l) = h ++ concatRec l

concatFoldr :: [[a]] -> [a]
concatFoldr l = foldr (++) [] l

rmChar :: Char -> String -> String
rmChar _ [] = []
rmChar a l = [ x | x <- l, x /= a]

rmCharsRec :: String -> String -> String
rmCharsRec [] a = a
rmCharsRec (x:xs) y = rmCharsRec xs $ rmChar x y
--rmCharApel:: String -> String -> String
--rmCharApel s1 s2 =


rmCharsFold :: String -> String -> String
rmCharsFold xs l = foldr (rmChar) l xs

{-rotate :: Int -> [Char] -> [Char]
rotate n s
  | length s < n || n < 0 = error "Alo gara, e mai mare/mic"
  | otherwise = b ++ a
  where (a,b)  = splitAt n s -}

lookUp :: Char -> [(Char, Char)] -> Char
lookUp n [] = n
lookUp n (h:l)
  | fst(h) == n = snd(h)
  | otherwise = lookUp n l

normalize :: String -> String
normalize [] = []
normalize (h:t)
 | isAlpha(h) = toUpper(h) : t1
 | isDigit(h) = h:t1
 | otherwise = normalize t
 where t1 = normalize t

reverseKey :: [(Char, Char)] -> [(Char, Char)]
reverseKey l = [(snd(x),fst(x)) | x<-l]

data Fruct
  = Mar String Bool
  | Portocala String Int

ionatanFaraVierme = Mar "Ionatan" False
goldenCuVierme = Mar "Golden Delicious" True
portocalaSicilia10 = Portocala "Sanguinello" 10
listaFructe = [Mar "Ionatan" False,
                Portocala "Sanguinello" 10,
                Portocala "Valencia" 22,
                Mar "Golden Delicious" True,
                Portocala "Sanguinello" 15,
                Portocala "Moro" 12,
                Portocala "Tarocco" 3,
                Portocala "Moro" 12,
                Portocala "Valencia" 2,
                Mar "Golden Delicious" False,
                Mar "Golden" False,
                Mar "Golden" True]

test_ePortocalaDeSicilia1 =
    ePortocalaDeSicilia (Portocala "Moro" 12) == True
test_ePortocalaDeSicilia2 =
    ePortocalaDeSicilia (Mar "Ionatan" True) == False

test_nrFeliiSicilia = nrFeliiSicilia listaFructe == 52

ePortocalaDeSicilia :: Fruct -> Bool
ePortocalaDeSicilia (Portocala s n) = elem s ["Tarocco", "Moro", "Sanguinello"]
ePortocalaDeSicilia _ = False

felii :: Fruct -> Int
felii (Portocala s n) = n

nrFeliiSicilia :: [Fruct] -> Int
nrFeliiSicilia [] = 0
nrFeliiSicilia (h:l)
  | ePortocalaDeSicilia h = felii h + nrFeliiSicilia l
  | otherwise = nrFeliiSicilia l

isMAr :: Fruct -> Bool
isMAr (Mar a b) = True
isMAr _ = False

areVierme :: Fruct -> Int
areVierme (Mar a b)
  | b = 1
  | otherwise = 0


nrMereViermi :: [Fruct] -> Int
nrMereViermi [] = 0
nrMereViermi (h:l)
  | isMAr h = areVierme h + nrMereViermi l
  | otherwise = nrMereViermi l

test_nrMereViermi = nrMereViermi listaFructe == 2

type Nume = String
type NumeA = String
type Rasa = String
data Animal
  = Pisica NumeA
  | Caine Nume Rasa

vorbeste :: Animal -> String
vorbeste (Pisica n) = "Meow"
vorbeste (Caine n r) = "Ham"

elise = Pisica "Elise"
azorel = Caine "Azorel" "Alb"

rasa :: Animal -> Maybe String
rasa (Caine a b) = Just b
rasa (Pisica c) = Nothing


type Numee = String
data Prop
  = Var Numee
  | F
  | T
  | Not Prop
  | Prop :|: Prop
  | Prop :&: Prop
  | Prop :->: Prop
  | Prop :<->: Prop
  deriving (Eq, Read)
infixr 2 :|:
infixr 3 :&:

p1 :: Prop
p1 = (Var "P" :|: Var "Q") :&: (Var "P" :&: Var "Q")

p2 :: Prop
p2 = (Var "P" :|: Var "Q") :&: (Not (Var "P") :&: Not (Var "Q"))

p3 :: Prop
p3 = (Var "P" :&: (Var "Q" :|: Var "R")) :&: ((Not (Var "P") :|: Not (Var "Q")) :&: (Not (Var "P") :|: Not (Var "Q")))

instance Show Prop where
  show (Var nume)= nume
  show (a :|: b) = "(" ++ show a ++ "|" ++ show b ++ ")"
  show (a :&: b) = "(" ++ show a ++ "&" ++ show b ++ ")"
  show (a :->: b) = "(" ++ show a ++ "->" ++ show b ++ ")"
  show (a :<->: b) = "(" ++ show a ++ "<->" ++ show b ++")"
  show (Not p) = "(~" ++ show p ++ ")"
  show F = "F"
  show T = "T"

test_ShowProp :: Bool
test_ShowProp =
    show (Not (Var "P") :&: Var "Q") == "((~P)&Q)"

eSfar :: Char -> Bool
eSfar c = elem c ['!', '.', '?', ':']

nrProp:: String -> Int
nrProp [] = 0
nrProp (h:n)
  | eSfar h = 1 + nrProp n
  | otherwise = nrProp n

liniiN :: Int -> [[Int]] -> Bool
liniiN n l = foldr (&&) True (map (\x-> if x <0 then False else True) (concat (map (\x -> if length x == n then x else []) l)))

makeList:: Int -> Int -> [(Int,Int)]
makeList a b = [(a,b)]

data Punct = Pt [ Int ]
             deriving Show


data Arb = Vid | J Int | N Arb Arb
           deriving Show

apare:: Char -> String -> Int
apare c [] = 0
apare c (h:s2)
  | c == h = 1 + apare c s2
  | otherwise = apare c s2

aparitii:: String -> String -> [(Char,Int)]
aparitii s1 s2 = [(h, apare h s2) | h <- s1]
{-
data Expr = Con a
          | Sum (Expr a) (Expr a)
          | Mul (Expr a) (Expr a)
          | Div (Expr a) (Expr a)

data Ops = Sum | Mul | Div

data Arb a = Leaf a
          | Node Ops (Arb a) (Arb a)
-}

factori2 :: Int -> [Int]
factori2 n = [ d | d <- [1..n], n `rem` d == 0]

fDiviz:: [Int] -> Int -> Int ->[[Int]]
fDiviz l n m = [factori2 y | (x,y)<-zip l [0..], x>=n, x<=m]

--liniiN :: Int -> [[Int]] -> Bool
--liniiN n l = foldr (&&) True (map (\x-> if x <0 then False else True) (concat (map (\x -> if length x == n then x else []) l)))
--factori1 :: Int -> [Int]
--factori1 n = [ d | d <- [1..n], n `rem` d == 0]
let d = [1..n]
sumPrim :: [Int] -> Int
sumPrim l = foldr (+) 0 (map (\x -> if x<2 || length(map)== 2  then 0 else x) l)

sumPrim1 :: [Int] -> Int
sumPrim1 l = map ()

data Pereche = P Int Int deriving Show

data Lista = L  [Pereche ] deriving  Show

data Exp = I Int | Add Exp Exp | Mul Exp Exp

class ClassExp m where

--show (Mul (Add (I 1) (I 2)) (I 3)) = “((1 + 2) * 3)”

instance Show Exp where
    show(I a) =   ord(a)
    show (Add a b) = "(" ++ show a ++ " + " ++ show b ++ ")"
    show (Mul a b) = "(" ++ show a ++ " * " ++ show b ++ ")"
 toExp ( L [ P 1 2, P 2 3 , P 5 3] )  =  Mul (Add (I 1) (I 2)) (Mul (Add (I 2) (I 3)) (Add (I 5) (I 3)))


    instance ClassExp Lista where
      toExp(Pt []) = []
      toArb (Pt (x:xs)) = Mul (A x) (Add(Pt xs))

      import Test.QuickCheck
      import Data.Maybe
      {- Monada Maybe este definita in GHC.Base
        -}
      instance Monad Maybe where
        return = Just
        Just va  >>= k   = k va
        Nothing >>= _   = Nothing


      instance Applicative Maybe where
        pure = return
        mf <*> ma = do
          f <- mf
          va <- ma
          return (f va)

      instance Functor Maybe where
        fmap f ma = pure f <*> ma


      (<=<) :: (a -> Maybe b) -> (c -> Maybe a) -> c -> Maybe b
      f <=< g = (\ x -> g x >>= f)

      f1 :: String -> Maybe Int
      f1 x = if length x > 10 then Just $ length x else Nothing

      g1 :: Int -> Maybe String
      g1 x = if x > 0 then Just $ concat $replicate x "ab" else Nothing

      f2, f3, f4 :: Int -> Maybe Int
      f2 x = if x > 10 then Just $ x * x else Nothing
      f3 x = if x > 15 then Just $ x + x else Nothing
      f4 x = if x > 20 then Just $ x * x * x else Nothing

      asoc :: (Int -> Maybe Int) -> (Int -> Maybe Int) -> (Int -> Maybe Int) -> Int -> Bool
      asoc f g h x = (h <=< (g <=< f) $ x) == ((h <=< g) <=< f $ x)

      pos :: Int -> Bool
      pos  x = if (x>=0) then True else False

      foo :: Maybe Int ->  Maybe Bool
      foo  mx =  do
           x <- mx
           return (pos x)

      addM1 :: Maybe Int -> Maybe Int -> Maybe Int
      addM1 (Just x) (Just y) = Just $ x + y
      addM1 _ _ = Nothing


      addM :: Maybe Int -> Maybe Int -> Maybe Int
      addM mx my =  do
        x <- mx
        y <- my
        return $ x + y


      isPos :: Int -> Maybe Bool
      isPos x = if (x>= 0) then Just True else Just False


      mapMaybeB :: (a -> Maybe b) -> [a] -> Maybe [b]
      mapMaybeB f xs = Just $ map fromJust ( filter isJust (map f xs))

      type Input = String
type Output = String
type InOutWorld = (Input, Output)
type MyIOState a = State InOutWorld a
newtype State s a = State {runState :: s -> (a,s)}

instance Monad (State s) where
  return x = State (\ s -> (x,s))
  ma >>= k = State f
      where f s1 = let
                      (va, s2) = runState ma s1
                      (vb, s3) = runState (k va) s2
                   in (vb, s3)

instance Applicative (State s) where
  pure = return
  mf <*> ma = do { f <- mf; a <- ma; return (f a) }
instance Functor (State s) where
  fmap f ma = do { a <- ma; return (f a) }

 MyIOState a = State {runState :: (Input, Output) -> (a,(Input, Output))}

 getMyChar MyIOState Char
 getMyChar State f =
    where f (i,o) -> (head i,(tail i,o))

putMyChar Char -> MyIOState ()
putMyChar c = State(\(i,o)->((),(i, o ++ [c])))


newtype WriterS a = Writer { runWriter :: (a, String) }


instance  Monad WriterS where
  return va = Writer (va, "")
  ma >>= k = let (va, log1) = runWriter ma
                 (vb, log2) = runWriter (k va)
             in  Writer (vb, log1 ++ log2)


instance  Applicative WriterS where
  pure = return
  mf <*> ma = do
    f <- mf
    a <- ma
    return (f a)

instance  Functor WriterS where
  fmap f ma = pure f <*> ma

tell :: String -> WriterS ()
  tell log = Writer ((), log)

logVriter Int -> WriterS
logVriter = do
  tell ("asta e "++ x)
  return (x+1)
logW2 Int ->WriterS
logW2 = do
  y<-logVriter x
  return y


  newtype Writer a = Writer { runWriter :: (a, [LeafCode]) } 


  instance  Monad Writer where
    return va = Writer (va, [])
    ma >>= k = let (va, log1) = runWriter ma
                   (vb, log2) = runWriter (k va)
               in  Writer (vb, log1 ++ log2)


  instance  Applicative Writer where
    pure = return
    mf <*> ma = do
      f <- mf
      a <- ma
      return (f a)

  instance  Functor Writer where
    fmap f ma = pure f <*> ma

tell :: String -> WriterLS ()
tell log = Writer ((), [log])

paths :: Arb a -> Integer -> [[Direction]]
paths (Leaf a) = [[]]
paths (Node x L M R) = map (x:) (paths L ++ paths M ++ paths R)

leafCodes :: Arb -> Integer -> Writer ()
leafcodes a x = Writer(a, [log] ++ findPath a x )
