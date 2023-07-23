// actions.ts
const INCREASE = 'counter/INCREASE';
const DECREASE = 'counter/DECREASE';

export type IncreaseAction = { type: typeof INCREASE };
export type DecreaseAction = { type: typeof DECREASE };

export const increase = (): IncreaseAction => ({ type: typeof INCREASE });
export const decrease = (): DecreaseAction => ({ type: typeof DECREASE });

// reducer.ts
interface CounterState {
  number: number;
}

const initialState: CounterState = {
  number: 0,
};

type CounterAction = IncreaseAction | DecreaseAction;

function counter(
  state: CounterState = initialState,
  action: CounterAction,
): CounterState {
  switch (action.type) {
    case INCREASE:
      return {
        number: state.number + 1,
      };
    case DECREASE:
      return {
        number: state.number - 1,
      };
    default:
      return state;
  }
}

export default counter;
