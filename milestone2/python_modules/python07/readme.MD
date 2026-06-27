per tournament.py

fact.create_base().name
Sono tre passi in catena:

fact → è un oggetto, tipo FlameFactory()
.create_base() → chiama il metodo che hai definito, che ritorna Flameling()
.name → accede all'attributo name di Flameling, che hai settato nell'__init__ come "Flameling"
--------------------
strat.__class__.__name__
Anche qui tre passi:

strat → è un oggetto, tipo NormalStrategy()
.__class__ → è un attributo che ogni oggetto Python ha sempre — punta alla classe da cui è stato creato, quindi NormalStrategy
.__name__ → prende il nome di quella classe come stringa, quindi "NormalStrategy"
.replace("Strategy", "") toglie la parola "Strategy" → "Normal"

.__class__.__name__ è un attributo built-in di Python, ce l'hanno tutti gli oggetti automaticamente