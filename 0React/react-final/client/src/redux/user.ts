import { createSlice, createAsyncThunk } from '@reduxjs/toolkit';
import * as authAPI from '../lib/api/auth';

interface UserState {
  user: any;
  checkError: Error | null;
}

const initialState: UserState = {
  user: null,
  checkError: null,
};

export const tempSetUser = createAsyncThunk('user/tempSetUser', async (user: any) => {
  return user;
});
export const check = createAsyncThunk('user/check', authAPI.check);


export const logout = createAsyncThunk(
  "user/logout",
  async () => {
    try {
      await authAPI.logout();
      localStorage.removeItem('user');
    } catch (err : any) {
      console.log(err)
    }
  }
);

const userSlice = createSlice({
  name: 'user',
  initialState,
  reducers: {},
  extraReducers: (builder) => {
    builder.addCase(tempSetUser.fulfilled, (state, { payload: user }) => {
      state.user = user;
    });
    builder.addCase(check.fulfilled, (state, { payload: user }) => {
      state.user = user;
      state.checkError = null;
    });
    builder.addCase(check.rejected, (state, { payload: error }) => {
      state.user = null;
      state.checkError = error as Error;
    });
    builder.addCase(logout.fulfilled, (state) => {
      state.user = null;
    });
  },
});

export default userSlice.reducer;
