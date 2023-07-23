import { createSlice, createAsyncThunk, PayloadAction } from '@reduxjs/toolkit';
import * as authAPI from '../lib/api/auth';

interface AuthState {
  register: {
    username: string;
    password: string;
    passwordConfirm: string;
  };
  login: {
    username: string;
    password: string;
  };
  auth: any;
  authError: any;
}

const initialState: AuthState = {
  register: {
    username: '',
    password: '',
    passwordConfirm: '',
  },
  login: {
    username: '',
    password: '',
  },
  auth: null,
  authError: null,
};

export const login = createAsyncThunk(
  "auth/login",
  async ({ username, password  } : any, { rejectWithValue }) => {
    try {
      const res = await authAPI.login({ username, password });
      const {data, status, statusText} = res;
      return {data, status, statusText};
      
    } catch (err : any) {
      return rejectWithValue(err.response.status);
    }
  }
);

export const register = createAsyncThunk(
  "auth/register",
  async ({ username, password  } : any, { rejectWithValue }) => {
    try {
      const res = await authAPI.register({ username, password });
      const {data, status, statusText} = res;
      return {data, status, statusText};
      
    } catch (err : any) {
      return rejectWithValue(err.response.status);
    }
  }
);

const authSlice = createSlice({
  name: 'auth',
  initialState,
  reducers: {
    changeLoginField: (state, { payload: { key , value }} ) => {
      (state.login as any)[key] = value;
    },
    changeRegisterField: (state, { payload: { key, value }} )=> {
      (state.register as any)[key] = value;
    },
    initializeLogin: (state) => {
      state.login = initialState.login;
      state.authError = null;
    },
    initializeRegister: (state) => {
      state.register = initialState.register;
      state.authError = null;
    },
  },
  extraReducers: (builder) => {
    builder.addCase(register.fulfilled, (state, action) => {
      console.log(action)
      state.auth = action.payload
      state.authError = null;
    });
    builder.addCase(register.rejected, (state, action) => {
      console.log(action)
      state.authError = action.payload;
    });
    builder.addCase(login.fulfilled, (state, action) => {
      state.auth = action.payload;
      state.authError = null;
    });
    builder.addCase(login.rejected, (state, action) => {
      state.authError = action.payload;
    });
  },
});

export const { changeLoginField, changeRegisterField, initializeLogin, initializeRegister } = authSlice.actions;

export default authSlice.reducer;
